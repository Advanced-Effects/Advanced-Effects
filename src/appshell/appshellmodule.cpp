#include "appshellmodule.h"

#include <QQmlEngine>

// UI types
#include "view/mainwindowtitleprovider.h"
#include "view/appmenumodel.h"

// Links this module to appshell.qrc file
//
// We put this here outside of ae::appshell namespace
// because Q_INIT_RESOURCE doesn't work inside a namespace
static void init_appshell_qrc() {
    Q_INIT_RESOURCE(appshell);
};

namespace ae::appshell {

std::string AppShellModule::moduleName() const {
    return "AppShell";
};

void AppShellModule::registerResources() {
    init_appshell_qrc();
};

void AppShellModule::registerUiTypes() {
    qmlRegisterType<AppMenuModel>("AdvancedEffects.AppShell", 1, 0, "AppMenuModel");
    qmlRegisterType<MainWindowTitleProvider>("AdvancedEffects.AppShell", 1, 0, "MainWindowTitleProvider");
};

};
