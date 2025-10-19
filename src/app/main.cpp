#include "application.h"

#include <QCoreApplication>
#include <QQmlApplicationEngine>
#include <QApplication>

#include "commandlineparser.h"

// Modules
#include "global/globalmodule.h"
#include "diagnostics/diagnosticsmodule.h"
#include "autobot/autobotmodule.h"
#include "draw/drawmodule.h"
#include "multiinstances/multiinstancesmodule.h"
#include "extensions/extensionsmodule.h"
#include "actions/actionsmodule.h"
#include "context/contextmodule.h"
#include "ui/uimodule.h"
#include "shortcuts/shortcutsmodule.h"
#include "accessibility/accessibilitymodule.h"
#include "uicomponents/uicomponentsmodule.h"
#include "dockwindow/dockmodule.h"
#include "network/networkmodule.h"
#include "learn/learnmodule.h"
#include "languages/languagesmodule.h"
#include "workspace/workspacemodule.h"
#include "projectscene/projectscenemodule.h"
#include "appshell/appshellmodule.h"

// Pull QQmlApplicationEngine
#include "modularity/ioc.h"
#include "ui/iuiengine.h"

using namespace app::app;

// Setup stuff.
// Loads environment variables, Qt theme, etc. etc.
void initialAppSetup() {

};

// With modules we load QML code and types.
// .qrc files, C++ types, ...
void loadApplicationModules(std::shared_ptr<Application> application) {
    application->addModule(new muse::diagnostics::DiagnosticsModule());
    application->addModule(new muse::actions::ActionsModule());
    application->addModule(new muse::autobot::AutobotModule());
    application->addModule(new muse::draw::DrawModule());
    application->addModule(new muse::mi::MultiInstancesModule());
    application->addModule(new muse::workspace::WorkspaceModule());
    application->addModule(new muse::accessibility::AccessibilityModule());
    application->addModule(new muse::learn::LearnModule());
    application->addModule(new muse::languages::LanguagesModule());
    application->addModule(new mu::context::ContextModule());
    application->addModule(new muse::ui::UiModule());
    application->addModule(new muse::uicomponents::UiComponentsModule());
    application->addModule(new muse::dock::DockModule());
    application->addModule(new muse::shortcuts::ShortcutsModule());
    application->addModule(new muse::network::NetworkModule());

    application->addModule(new app::projectscene::ProjectSceneModule());
    application->addModule(new app::appshell::AppShellModule());
};

// We get the QQmlApplicationEngine from UiEngine.
// because it injects the object 'ui' which we use to get
// theme colors. See: `setContextProperty("ui", this)`
QQmlApplicationEngine *pullApplicationEngine(std::shared_ptr<Application> app) {
    std::shared_ptr<muse::ui::IUiEngine> uiEngine = app->ioc()->resolve<muse::ui::IUiEngine>("ui");
    if (!uiEngine) {
        qWarning() << "UiEngine was not found. QQmlApplicationEngine cannot be pulled. in `main.cpp:pullApplicationEngine()`";
        return nullptr;
    }

    return uiEngine->qmlAppEngine();
};

int main(int argc, char *argv[]) {
    initialAppSetup();

    QApplication *qApplication = new QApplication(argc, argv);
    /* ============= Initialize command line arguments ============= */
    CommandLineParser commandLineParser;
    commandLineParser.init();
    commandLineParser.parse(argc, argv);
    commandLineParser.processBuiltinArgs(*qApplication);
    CmdOptions options/* = commandLineParser.options()*/;

    /* ============= First, load the Qt resources ============= */
    auto application = Application::create(options);
    // Add modules to application
    loadApplicationModules(application);
    // Load the modules BEFORE pulling QmlAppEngine!
    // (uimodule.cpp creates and registers IUiEngine)
    application->initalizeModules();
    application->perform(); //idk what this does

    /* ============= Initialize Qt Application ============= */
    QQmlApplicationEngine *engine = pullApplicationEngine(application);
    if (!engine) {
        return EXIT_FAILURE;
    }

    return application->exec(*qApplication, commandLineParser, *engine);

    application->deinitModules();
    application->finish(); //idk what this does
    delete qApplication;
};
