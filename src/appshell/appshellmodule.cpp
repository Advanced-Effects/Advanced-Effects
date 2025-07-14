#include "appshellmodule.h"

#include <QQmlEngine>


static void appshell_init_qrc() {
    Q_INIT_RESOURCE(appshell);
};

void AppShellModule::moduleName() const {
    return "appshell"
};

void AppShellModule::registerExports() {

};

void AppShellModule::resolveImports() {

};

void AppShellModule::registerResources() {
    appshell_init_qrc();
};

// Register C++ QtQuick types
void AppShellModule::registerUiTypes() {
    //qmlRegisterType<Name>("AdvancedEffects.AppShell", 1, 0, "Name");
};

void AppShellModule::onPreInit() {};

void AppShellModule::onInit() {};

void AppShellModule::onAllInitied() {};

void AppShellModule::onDeinit() {};
