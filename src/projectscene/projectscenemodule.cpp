#include "projectscenemodule.h"

#include <memory>

#include "modularity/ioc.h"
#include "ui/iuiactionsregister.h"
#include "ui/iinteractiveuriregister.h"

#include "internal/projectactionscontroller.h"
#include "internal/projectuiactions.h"
#include "internal/toolbar/toolactioncontroller.h"
#include "internal/toolbar/toolbaractions.h"

#include "view/canvas/applicationcanvas.h"
#include "view/timeline/keysview.h"
#include "view/toolbarmodel.h"

// Links the module to the .qrc file
// WE put it outside of the app::appshell namespace
// because Q_INIT_RESOURCE can't be located inside a namespace
// (either it fails with error "couldn't find qLinkResources_app()")
static void projectscene_init_qrc()
{
    Q_INIT_RESOURCE(projectscene);
};

namespace app::projectscene {

using namespace muse;

ProjectSceneModule::ProjectSceneModule()
        : m_actionsController(nullptr)
        , m_projectActions(nullptr) {};

std::string ProjectSceneModule::moduleName() const {
    return "projectscene";
};

void ProjectSceneModule::registerResources() {
    projectscene_init_qrc();
};

void ProjectSceneModule::registerExports() {
        qmlRegisterType<ToolBarModel>("App.ProjectScene", 1, 0 , "ToolBarModel");
        qmlRegisterType<ApplicationCanvas>("App.ProjectScene", 1, 0, "ApplicationCanvas");
        qmlRegisterType<KeysView>("App.ProjectScene", 1, 0, "KeysView");

        m_actionsController = std::make_shared<ProjectActionController>(iocContext());
        m_projectActions = std::make_shared<ProjectUiActions>(m_actionsController, iocContext());
        m_toolbarController = std::make_shared<ToolActionController>(iocContext());
        m_toolbarActions = std::make_shared<ToolBarUiActions>(m_toolbarController, iocContext());
};

void ProjectSceneModule::resolveImports() {
        auto ir = ioc()->resolve<ui::IInteractiveUriRegister>(moduleName());
        if (ir) {
                ir->registerUri(Uri("app://edit"), ui::ContainerMeta(ui::ContainerType::PrimaryPage));
                ir->registerUri(Uri("app://new"), ui::ContainerMeta(ui::ContainerType::QmlDialog, "App/ProjectScene/NewProjectDialog/NewProject.qml"));
        }

        auto ar = ioc()->resolve<ui::IUiActionsRegister>(moduleName());
        if (ar) {
                ar->reg(m_projectActions);
                ar->reg(m_toolbarActions);
        }
};

void ProjectSceneModule::onInit(const IApplication::RunMode& mode) {
        m_actionsController->init();
        m_toolbarController->init();
};

};
