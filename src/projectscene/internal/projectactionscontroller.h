#pragma once

#include <memory>
#include <string>

#include "modularity/ioc.h"
#include "actions/iactionsdispatcher.h"
#include "actions/actionable.h"
#include "actions/actiontypes.h"
#include "iinteractive.h"

#include "context/iglobalcontext.h"
#include "glax_core/model/document.hpp"
#include "../iprojectfilescontroller.h"

namespace app::projectscene {

using namespace muse;

class ProjectActionController
        : public Injectable
        , public actions::Actionable
{
        Inject<actions::IActionsDispatcher> dispatcher = { this };
        Inject<IInteractive> interactive = { this };
        Inject<IProjectFilesController> projectFiles = { this };

public:
        ProjectActionController(const modularity::ContextPtr& iocCtx)
                : Injectable(iocCtx) {};

        // This is where ACTIONS are registered
        void init();

private:
        // Opens the 'New Project' UI dialog
        // What actually creates new projects is the "open project" action
        void newProject();

        // Action to open a project. Expects two arguments:
        // 0. The URL to the file
        void openProject(const muse::actions::ActionData& args);
        void openProject(QUrl fileUrl);
        void openProject(std::shared_ptr<Document> document);

        void saveProject();
        void closeProject();
        void importAsset();
};

}
