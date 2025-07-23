#pragma once

#include <string>

#include "modularity/imodulesetup.h"

namespace ae::appshell {

using namespace muse::modularity;

class AppShellModule : public IModuleSetup {
public:
    std::string moduleName() const override;

    void registerResources() override;
    void registerUiTypes() override;
};

};
