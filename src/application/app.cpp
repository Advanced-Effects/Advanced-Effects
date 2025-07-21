#include "app.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

namespace ae::app {

Application::Application() {};

Application::~Application() {
    deinitModules();
};

QQuickWindow* loadApplicationAndCreateWindow(QQmlApplicationEngine* engine) {
    // Load the QML file to the App Engine
    const QUrl url("qrc:/qml/Main.qml");
    engine->load(url);

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

void Application::initalizeModules() {};

void Application::deinitModules() {};

};
