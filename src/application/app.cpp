#include "app.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

#include "global/globalmodule.h"

//! NOTE Separately to initialize logger and profiler as early as possible
static muse::GlobalModule globalModule;

namespace ae::app {

Application::Application() {};

Application::~Application() {
    deinitModules();
};

const QUrl applicationMainFile("qrc:/qml/Main.qml");

QQuickWindow* loadApplicationAndCreateWindow(QQmlApplicationEngine* engine) {
    // Load the QML file to the App Engine
    engine->load(applicationMainFile);

    // Get the first element (QtQuick Window)
    auto *rootElement = engine->rootObjects().value(0);
    if (!rootElement) {
        return nullptr;
    };

    // If it exists, cast it to a QQuickWindow and return it
    return qobject_cast<QQuickWindow *>(rootElement);
};

int Application::exec(
    CommandLineParser &parser,
    QApplication* app,
    QQmlApplicationEngine* engine
) {
    // Create app window
    auto *window = loadApplicationAndCreateWindow(engine);
    if (!window) {
        qWarning("Application didn't load");
        return EXIT_FAILURE;
    }

    window->show();

    return app->exec();
};

void Application::addModule(muse::modularity::IModuleSetup* module) {
    _modules.push_back(module);
};

void Application::initalizeModules() {
    for (auto *m : _modules) {
        m->registerResources();
    };

    for (auto *m : _modules) {
        m->registerExports();
    };

    for (auto* m : _modules) {
        m->registerUiTypes();
        m->resolveImports();
        m->registerApi();
    }
};

void Application::deinitModules() {
    globalModule.invokeQueuedCalls();

    for (muse::modularity::IModuleSetup* m : _modules) {
        m->onDeinit();
    }

    globalModule.onDeinit();

    for (muse::modularity::IModuleSetup* m : _modules) {
        m->onDestroy();
    }

    globalModule.onDestroy();

    // Delete modules
    qDeleteAll(_modules);
    _modules.clear();
    muse::modularity::_ioc()->reset();
};

};
