#pragma once

#include "async/asyncable.h"
#include "actions/actionable.h"
#include "actions/actiontypes.h"

#include "modularity/ioc.h"
#include "iinteractive.h"
#include "actions/iactionsdispatcher.h"
#include "ui/iuiactionsregister.h"
#include "context/iglobalcontext.h"
#include "context/iuicontextresolver.h"

using namespace mu;

namespace app::appshell {

class ToolActionController : public muse::actions::Actionable
                           , public muse::async::Asyncable
                           , public muse::Injectable
{
        INJECT(muse::actions::IActionsDispatcher, dispatcher)
        INJECT(muse::ui::IUiActionsRegister, actionRegister)

public:
        ToolActionController(const muse::modularity::ContextPtr& iocCtx);
        ~ToolActionController() = default;

        void init();

private:
        void toggleSelectedTool();
};

};
