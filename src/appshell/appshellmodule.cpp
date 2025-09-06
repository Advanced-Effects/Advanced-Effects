#include "appshellmodule.h"

#include <QQmlEngine>

#include "view/navigableappmenumodel.h"
#include "view/mainwindowtitleprovider.h"
#include "view/toolselectionmodel.h"

#include "modularity/ioc.h"
#include "ui/iinteractiveuriregister.h"

// Register UI Actions
#include "internal/appshellactionscontroller.h"
#include "internal/appshellactions.h"

// Links the module to the .qrc file
// WE put it outside of the app::appshell namespace
// because Q_INIT_RESOURCE can't be located inside a namespace
// (either it fails with error "couldn't find qLinkResources_app()")
static void appshell_init_qrc()
{
    Q_INIT_RESOURCE(appshell);
};

namespace app::appshell {

AppShellModule::AppShellModule() {};

std::string AppShellModule::moduleName() const {
    return "appshell";
};

void AppShellModule::registerResources() {
    appshell_init_qrc();
};

void AppShellModule::registerExports() {
        qmlRegisterType<MainWindowTitleProvider>("App.AppShell", 1, 0, "MainWindowTitleProvider");
        qmlRegisterType<NavigableAppMenuModel>("App.AppShell", 1, 0, "AppMenuModel");
        qmlRegisterType<ToolSelectionModel>("App.AppShell", 1, 0, "ToolSelectionModel");

        m_actionsController = std::make_shared<AppshellActionController>(iocContext());
        m_appshellActions = std::make_shared<AppshellUiActions>(m_actionsController, iocContext());
};

void AppShellModule::resolveImports() {
        auto ir = ioc()->resolve<ui::IInteractiveUriRegister>(moduleName());
        if (ir) {
                ir->registerUri(Uri("app://edit"), ui::ContainerMeta(ui::ContainerType::PrimaryPage));
        }

        auto ar = ioc()->resolve<ui::IUiActionsRegister>(moduleName());
        if (ar) {
                ar->reg(m_appshellActions);
        }
};

};
