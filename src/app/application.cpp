#include "application.h"

#include <QQuickWindow>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QObject>

#include <QStringLiteral>
#include <QString>
#include <QUrl>

// tell our modules when application loads (initializeModules)
#include <QApplication>
#include <QMetaObject>

#include "commandlineparser.h"
#include "ui/internal/uiengine.h"

// Links this application with app.qrc
// WE put it outside of the app::appshell namespace
// because Q_INIT_RESOURCE can't be located inside a namespace
// (either it fails with error "couldn't find qLinkResources_app()")
static void app_init_qrc() {
    Q_INIT_RESOURCE(app); // app.qrc
}

namespace app::app {

Application::Application(const CmdOptions& options, const muse::modularity::ContextPtr& ctx)
    : muse::BaseApplication(ctx)
    , m_cmdOptions(options) {
    };

void Application::addModule(muse::modularity::IModuleSetup *module) {
    _modules.push_back(module);
};

std::shared_ptr<Application> Application::create(CmdOptions& options) {
    // NOTE: what is this Context thing used for?
    muse::modularity::ContextPtr ctx = std::make_shared<muse::modularity::Context>();
    // TODO ++m_lastID; // why do we increment m_lastID?
    //ctx->id = m_lastID;
    ctx->id = -1; //! NOTE At the moment global ioc

    auto app = std::make_shared<Application>(options, ctx);
    return app;
};

void Application::initalizeModules() {
    m_globalModule.registerResources();
    for (auto *m : _modules) {
        m->registerResources();
    };

    m_globalModule.registerExports();
    for (auto *m : _modules) {
        m->registerExports();
    };

    m_globalModule.registerUiTypes();
    m_globalModule.resolveImports();
    m_globalModule.registerApi();
    for (auto* m : _modules) {
        m->registerUiTypes();
        m->resolveImports();
        m->registerApi();
    }

    IApplication::RunMode runMode = IApplication::RunMode::GuiApp;
    m_globalModule.onPreInit(runMode);
    for (auto *m : _modules) {
        m->onPreInit(runMode);
    }

    m_globalModule.onInit(runMode);
    for (auto *m : _modules) {
        m->onInit(runMode);
    }

    m_globalModule.onAllInited(runMode);
    for (auto *m : _modules) {
        m->onAllInited(runMode);
    }

    // When Qt application starts,
    // (where qApp is a global reference to the QApplication. No need to pass references around)
    QMetaObject::invokeMethod(qApp, [this]() {
        m_globalModule.onStartApp();
        for (auto *m : _modules) {
            m->onStartApp(); // tell our modules so
        }
    }, Qt::QueuedConnection);

}

void Application::deinitModules() {
    m_globalModule.invokeQueuedCalls();

    for (muse::modularity::IModuleSetup* m : _modules) {
        m->onDeinit();
    }

    m_globalModule.onDeinit();

    for (muse::modularity::IModuleSetup* m : _modules) {
        m->onDestroy();
    }

    m_globalModule.onDestroy();

    // Delete modules
    qDeleteAll(_modules);
    _modules.clear();
    muse::modularity::_ioc()->reset();
};

#if APP_LIST_QUI
void dumpTree(QObject *obj, int indent) {
    qDebug().noquote() << QString(indent, ' ') << obj->metaObject()->className() << obj->objectName();
    for (QObject *child : obj->children()) {
        dumpTree(child, indent + 2);
    }
}
#endif

// Loads the Main.qml file and returns the first element
// (which is a QtQuick `Window`)
QQuickWindow *loadApplicationAndCreateWindow(QQmlApplicationEngine &engine) {
    // We load the Main.qml file to the application engine
    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    engine.load(url);

#if APP_LIST_QUI
    const QList<QObject*> rootObjects = engine.rootObjects();
    for (QObject *root : rootObjects) {
        dumpTree(root, 0);
    }
#endif

    // We get the root element (Main.qml)
    QObject *rootUiElement = engine.rootObjects().value(0);

    // Make sure it exists
    if (!rootUiElement) {
        qWarning("\nMain.qml wasn't loaded correctly because no element was found in QQmlApplicationEngine OR there was an error.");
        return nullptr;
    }

    // If it exists, get the root element (Window) and cast it to a QQuickWindow
    return qobject_cast<QQuickWindow *>(rootUiElement);
}

int Application::exec(
        QCoreApplication& app,
        CommandLineParser& parser,
        QQmlApplicationEngine& engine) {
    // Include files from 'app.qrc'
    app_init_qrc();

    QQuickWindow *window = loadApplicationAndCreateWindow(engine);
    if (!window) return EXIT_FAILURE;
    // Set the window to open as Frameless if possible
    window->setFlags(Qt::FramelessWindowHint | Qt::Window);
    // Then show it
    window->show();

    // Start application loop (to avoid the application from quitting immediately)
    return app.exec();

    // After application runs, remember to deinit all the modules
    deinitModules();
};

void Application::perform() {};
void Application::finish() {};

};
