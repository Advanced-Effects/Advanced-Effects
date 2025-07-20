#include "appshellmodule.h"

#include <QQmlEngine>

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

};
