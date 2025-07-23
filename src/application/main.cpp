#include <memory>

#include <QQmlApplicationEngine>
#include <QApplication>
#include <QDirIterator>

#include "app.h"
#include "cmdline.h"

#include "ui/uimodule.h"
#include "uicomponents/uicomponentsmodule.h"
#include "appshellmodule.h"

using namespace ae::app;

int main(int argc, char *argv[]) {
    Application application;
    application.addModule(new muse::ui::UiModule());
    application.addModule(new muse::uicomponents::UiComponentsModule());
    application.addModule(new ae::appshell::AppShellModule());

    CommandLineParser parser;
    parser.init();
    parser.parse(argc, argv);

    auto* qtApp = new QApplication(argc, argv);
    auto *engine = new QQmlApplicationEngine();

    /* ================ DEBUG TRICKS =============== */

    // If environment variable "APP_LIST_QRT" is defined and set to '1', show Qt Resource Tree
    if(qgetenv("APP_LIST_QRT") == "1") {
        qDebug() << engine->importPathList();
        QDirIterator qrc(":", QDirIterator::Subdirectories);
        while(qrc.hasNext()) { qWarning() << qrc.next(); }
    };

    return application.exec(parser, qtApp, engine);
};
