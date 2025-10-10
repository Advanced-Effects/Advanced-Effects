#pragma once

#include <string>

#include "modularity/imodulesetup.h"

namespace app::projectscene {

class ProjectSceneModule : public muse::modularity::IModuleSetup {
public:
        ProjectSceneModule();
        ~ProjectSceneModule() = default;

        std::string moduleName() const override;

        void registerResources() override;
        void registerExports() override;
};

};
