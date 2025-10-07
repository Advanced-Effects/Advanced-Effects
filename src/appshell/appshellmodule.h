#pragma once

#include <string>

#include "modularity/imodulesetup.h"

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

private:
        std::shared_ptr<AppshellActionController> m_actionsController;
        std::shared_ptr<AppshellUiActions> m_appshellActions;
        std::shared_ptr<ToolBarUiActions> m_toolbarActions;
};

};
