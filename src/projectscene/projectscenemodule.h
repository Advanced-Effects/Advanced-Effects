#pragma once

#include <string>

#include "modularity/imodulesetup.h"

#include "internal/projectactionscontroller.h"
#include "internal/projectuiactions.h"
#include "internal/toolbar/toolactioncontroller.h"
#include "internal/toolbar/toolbaractions.h"
#include "internal/projectfilescontroller.h"

namespace app::projectscene {

using namespace muse;

class ProjectSceneModule : public muse::modularity::IModuleSetup {
public:
        ProjectSceneModule();
        ~ProjectSceneModule() = default;

        std::string moduleName() const override;

        void registerResources() override;
        void registerExports() override;
        void resolveImports() override;
        void onInit(const IApplication::RunMode& mode) override;
private:
        std::shared_ptr<ProjectActionController> m_actionsController;
        std::shared_ptr<ProjectUiActions> m_projectActions;
        std::shared_ptr<ToolActionController> m_toolbarController;
        std::shared_ptr<ToolBarUiActions> m_toolbarActions;
        std::shared_ptr<ProjectFilesController> m_projectFilesController;
};

};
