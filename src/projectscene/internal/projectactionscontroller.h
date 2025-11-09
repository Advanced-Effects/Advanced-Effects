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

        // Opens the 'New Project' UI dialog
        // What actually creates new projects is the "open project" action
        void newProject();

        void openProject();

        void saveProject();
        void closeProject();
        void importAsset();
};

}
