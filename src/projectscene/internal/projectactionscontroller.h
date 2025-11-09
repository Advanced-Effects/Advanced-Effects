#pragma once

#include "modularity/ioc.h"
#include "actions/iactionsdispatcher.h"
#include "actions/actionable.h"
#include "iinteractive.h"


namespace app::projectscene {

using namespace muse;

class ProjectActionController
        : public Injectable
        , public actions::Actionable
{
        Inject<actions::IActionsDispatcher> dispatcher = { this };
        Inject<IInteractive> interactive = { this };

public:
        ProjectActionController(const modularity::ContextPtr& iocCtx)
                : Injectable(iocCtx) {};

        // This is where ACTIONS are registered
        void init();

        void openProject();
        void closeProject();
};

}
