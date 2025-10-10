#pragma once

#include "modularity/ioc.h"
#include "actions/iactionsdispatcher.h"
#include "actions/actionable.h"
#include "iinteractive.h"


using namespace muse;

namespace app::appshell {

class AppshellActionController : public Injectable, public actions::Actionable
{
        Inject<actions::IActionsDispatcher> dispatcher = { this };
        Inject<IInteractive> interactive = { this };

public:
        AppshellActionController(const modularity::ContextPtr& iocCtx)
                : Injectable(iocCtx) {};

        void init();
};

};
