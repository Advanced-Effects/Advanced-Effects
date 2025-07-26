#include <memory>

#include <QQmlApplicationEngine>
#include <QApplication>
#include <QDirIterator>

#include "accessibility/accessibilitymodule.h"
#include "app.h"
#include "cmdline.h"

// Application modules!!
#include "accessibility/accessibilitymodule.h"
#include "ui/uimodule.h"
#include "dockwindow/dockmodule.h"
#include "uicomponents/uicomponentsmodule.h"
#include "appshellmodule.h"

using namespace ae::app;

int main(int argc, char *argv[]) {
    /* ================ Load application modules ================ */
    Application application;
    application.addModule(new muse::accessibility::AccessibilityModule());
    application.addModule(new muse::ui::UiModule());
    application.addModule(new muse::uicomponents::UiComponentsModule());
    application.addModule(new muse::dock::DockModule());
    application.addModule(new ae::appshell::AppShellModule());

    /* ================ Setup variables ================ */
    CommandLineParser parser;
    parser.init();
    parser.parse(argc, argv);

    auto* qtApp = new QApplication(argc, argv);
    auto *engine = new QQmlApplicationEngine();
    engine->addImportPath(":/qml/");

    /* ================ DEBUG TRICKS =============== */

    // If environment variable "APP_LIST_QRT" is defined and set to '1', show Qt Resource Tree
    if(qgetenv("APP_LIST_QRT") == "1") {
        qDebug() << engine->importPathList();
        QDirIterator qrc(":", QDirIterator::Subdirectories);
        while(qrc.hasNext()) { qWarning() << qrc.next(); }
    };

    /* ================ Run application ================ */
    return application.exec(parser, qtApp, engine);
};
