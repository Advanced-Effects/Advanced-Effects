#pragma once

#include <string>

#include "modularity/imodulesetup.h"

namespace app::appshell {

class AppShellModule : public muse::modularity::IModuleSetup {
public:
    AppShellModule();
    ~AppShellModule() = default;

    std::string moduleName() const override;

    void registerResources() override;
    void registerExports() override;
    void resolveImports() override;
};

};
