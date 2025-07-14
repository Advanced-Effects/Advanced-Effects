#include "GuiApplication.h"

GuiApp::GuiApp(const modularity::ContextPtr& ctx)
    : muse::BaseApplication(ctx) {};

void GuiApp::addModule(muse::modularity::IModuleSetup* module) {
    m_modules.push_back(module);
};

void GuiApp::perform() {};

void GuiApp::finish() {};
