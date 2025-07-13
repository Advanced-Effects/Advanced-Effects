#include "AppCreation.h"

#include "GuiApplication.h"

// Modules
#include "appshell/appshellmodule.h"

using namespace muse::modularity;

std::shared_ptr<IApplication> newGuiApplication() const {
    ContextPtr ctx = std::make_shared<Context>();
    auto app = std::make_shared<GuiApp>(ctx);

    app->addModule(new ae::appshell::AppShellModule());

    return app;
};
