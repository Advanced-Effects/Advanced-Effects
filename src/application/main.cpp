#include <memory>

#include <QQmlApplicationEngine>
#include <QApplication>

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

    auto* app = new QApplication(argc, argv);

    return application.exec(parser, app);
};
