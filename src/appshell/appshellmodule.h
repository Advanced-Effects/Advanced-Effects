#pragma once

#include <string>

#include "modularity/imodulesetup.h"
#include "iapplication.h"

using namespace muse;

namespace app::appshell {

class AppshellUiActions;
class AppshellActionController;

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
};

};
