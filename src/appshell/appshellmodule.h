#pragma once

#include <memory>

#include "modularity/imodulesetup.h"

using namespace muse::modularity;

namespace ae::appshell {

class AppShellModule : public IModuleSetup {
public:
    std::string moduleName() const override;

    void registerExports() override;
    void resolveImports() override;

    void registerResources() override;
    void registerUiTypes() override;

    void onPreInit(const IApplication::RunMode& mode) override;
    void onInit(const IApplication::RunMode& mode) override;
    void onAllInitied(const IApplication::RunMode& mode) override;
    void onDeinit() override;
};

};
