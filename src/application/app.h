#pragma once

#include "modularity/imodulesetup.h"

namespace ae::app {

class Application {
public:
    Application();
    ~Application();

    void addModule(muse::modularity::IModuleSetup* module);

    int exec();

private:
    muse::modularity::IModuleSetup* _modules;

    void initalizeModules();
    void deinitModules();
};

};

