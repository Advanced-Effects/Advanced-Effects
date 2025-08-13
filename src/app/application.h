#pragma once

#include <memory>
#include <QList>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "global/internal/baseapplication.h"
#include "cmdoptions.h"
#include "commandlineparser.h"

#include "modularity/imodulesetup.h"
#include "global/globalmodule.h"

#include "modularity/ioc.h"
#include "global/iapplication.h"

namespace app::app {

class Application : public muse::BaseApplication {
public:
    //
    Application(
        const CmdOptions& options,
        const muse::modularity::ContextPtr& ctx
    );
    ~Application() = default;

    static std::shared_ptr<Application> create(CmdOptions &options);

    void addModule(muse::modularity::IModuleSetup* module);

    int exec(
        QCoreApplication& app,
        CommandLineParser& parser,
        QQmlApplicationEngine& engine);

    void perform() override;
    void finish() override;
    void initalizeModules();
    void deinitModules();

private:
    //! NOTE Separately to initialize logger and profiler as early as possible
    muse::GlobalModule m_globalModule;
    QList<muse::modularity::IModuleSetup*> _modules;

    CmdOptions m_cmdOptions;

};

};
