#include "toolactioncontroller.h"

using namespace app::appshell;

ToolActionController::ToolActionController(const muse::modularity::ContextPtr& iocCtx) : muse::Injectable(iocCtx) {};

void ToolActionController::init() {
        registerToolInputAction("select-tool", ToolIdentifier::selection);
};

void ToolActionController::registerAction(const muse::actions::ActionCode& code,
                                          std::function<void()> callback) {
        dispatcher()->reg(this, code, callback);
};

void ToolActionController::registerToolInputAction(const muse::actions::ActionCode& code, ToolIdentifier identifier) {
        registerAction(code, [this, identifier]() { toggleSelectedTool(identifier); });
};

void ToolActionController::toggleSelectedTool(ToolIdentifier identifier) {
        m_selectedTool = identifier;
};
