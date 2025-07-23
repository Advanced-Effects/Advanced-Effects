#pragma once

#include <vector>
#include <memory>

#include <QQmlApplicationEngine>
#include <QApplication>

#include "cmdline.h"
#include "modularity/imodulesetup.h"

namespace ae::app {

class Application {
public:
    Application();
    ~Application();

    void addModule(muse::modularity::IModuleSetup* module);

    int exec(
        CommandLineParser &parser,
        QApplication* app,
        QQmlApplicationEngine* engine
    );

private:
    std::vector<muse::modularity::IModuleSetup *> _modules;

    void initalizeModules();
    void deinitModules();
};

};
