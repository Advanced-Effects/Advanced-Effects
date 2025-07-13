#pragma once

#include <vector>

namespace ae {

class GuiApp : public muse::BaseApplication, public std::enable_shared_from_this<GuiApp> {
public:
    GuiApp(const muse::modularity::ContextPtr& ctx);

    void addModule(muse::modularity::IModuleSetup* module);

    void perform() override;
    void finish() override;

private:
    std::vector<muse::modularity::IModuleSetup*> m_modules;
};

};