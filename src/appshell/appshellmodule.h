#pragma once

#include <memory>
#include <string>

#include "modularity/imodulesetup.h"
#include "iapplication.h"

namespace ae::appshell {

using namespace muse::modularity;

class AppShellModule : public IModuleSetup {
public:
    std::string moduleName() const override;

    void registerResources() override;
};

};
