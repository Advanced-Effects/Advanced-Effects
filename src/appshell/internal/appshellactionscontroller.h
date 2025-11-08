#pragma once

#include "modularity/ioc.h"
#include "actions/iactionsdispatcher.h"
#include "actions/actionable.h"
#include "iinteractive.h"


using namespace muse;

namespace app::appshell {

class AppshellActionController : public Injectable, public actions::Actionable
{
        muse::Inject<actions::IActionsDispatcher> dispatcher = { this };
        muse::Inject<IInteractive> interactive = { this };

public:
        AppshellActionController(const modularity::ContextPtr& iocCtx)
                : Injectable(iocCtx) {};

        // This is where ACTIONS are registered,
        // where it is stated what they DO. (`IActionsDispatcher->reg()`)
        void init();

        void quitApplication();
        void openPreferencesDialog();

        void openFileDialog();
        void importFileDialog();
};

};
