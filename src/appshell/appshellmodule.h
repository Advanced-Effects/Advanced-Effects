#pragma once

#include <string>

#include "modularity/imodulesetup.h"
#include "iapplication.h"

#include "internal/toolbar/toolactioncontroller.h"

using namespace muse;

namespace app::appshell {

class AppshellUiActions;
class AppshellActionController;
class ToolBarUiActions;

class AppShellModule : public muse::modularity::IModuleSetup {
public:
        AppShellModule();
        ~AppShellModule() = default;

        std::string moduleName() const override;

        void registerResources() override;
        void registerExports() override;
        void resolveImports() override;

        void onInit(const IApplication::RunMode& mode) override;

private:
        std::shared_ptr<AppshellActionController> m_actionsController;
        std::shared_ptr<AppshellUiActions> m_appshellActions;
        std::shared_ptr<ToolBarUiActions> m_toolbarActions;
        std::shared_ptr<ToolActionController> m_toolActionsController;
};

};
