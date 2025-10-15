#include "appshellmodule.h"

#include <QQmlEngine>

#include "ui/uitypes.h"
#include "view/navigableappmenumodel.h"
#include "view/mainwindowtitleprovider.h"
#include "view/toolbarmodel.h"
#include "view/canvas/applicationcanvas.h"

#include "modularity/ioc.h"
#include "ui/iinteractiveuriregister.h"

// Register UI Actions
#include "internal/appshellactionscontroller.h"
#include "internal/appshellactions.h"
#include "internal/toolbar/toolbaractions.h"
#include "internal/toolbar/toolactioncontroller.h"

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
        qmlRegisterType<ToolBarModel>("App.AppShell", 1, 0, "ToolBarModel");

        qmlRegisterType<ApplicationCanvas>("App.AppShell", 1, 0, "ApplicationCanvas");

        m_actionsController = std::make_shared<AppshellActionController>(iocContext());
        m_appshellActions = std::make_shared<AppshellUiActions>(m_actionsController, iocContext());
        m_toolbarActions = std::make_shared<ToolBarUiActions>(m_actionsController, iocContext());
        m_toolActionsController = std::make_shared<ToolActionController>(iocContext());
};

void AppShellModule::resolveImports() {
        auto ir = ioc()->resolve<ui::IInteractiveUriRegister>(moduleName());
        if (ir) {
                ir->registerUri(Uri("app://edit"), ui::ContainerMeta(ui::ContainerType::PrimaryPage));
                ir->registerUri(Uri("app://preferences"), ui::ContainerMeta(ui::ContainerType::QmlDialog, "Preferences/PreferencesDialog.qml"));
        }

        auto ar = ioc()->resolve<ui::IUiActionsRegister>(moduleName());
        if (ar) {
                ar->reg(m_appshellActions);
        }
};

void AppShellModule::onInit(const IApplication::RunMode& mode) {
        m_actionsController->init();
        m_toolActionsController->init();
};


};
