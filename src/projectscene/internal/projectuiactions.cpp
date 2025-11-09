#include "projectuiactions.h"

#include "modularity/ioc.h"
#include "ui/uiaction.h"
#include "shortcuts/shortcutcontext.h"
#include "types/translatablestring.h"

using namespace muse;
using namespace muse::actions;
using namespace muse::ui;
using namespace app::projectscene;

ProjectUiActions::ProjectUiActions(std::shared_ptr<ProjectActionController> controller,
                                   const muse::modularity::ContextPtr& iocCtx)
        : muse::Injectable(iocCtx), m_controller(controller) {};

const UiActionList& ProjectUiActions::actionsList() const
{
        return m_actions;
}

bool ProjectUiActions::actionEnabled(const UiAction& act) const
{
        if (!m_controller->canReceiveAction(act.code)) {
        return false;
        }

        return true;
}

bool ProjectUiActions::actionChecked(const UiAction&) const
{
        return false;
}

async::Channel<ActionCodeList> ProjectUiActions::actionEnabledChanged() const
{
        return m_actionEnabledChanged;
}

async::Channel<ActionCodeList> ProjectUiActions::actionCheckedChanged() const
{
        return m_actionCheckedChanged;
}

const ui::UiActionList ProjectUiActions::m_actions = {
        // File menu
        UiAction("project-new",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "New Project")),
        UiAction("project-open",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Open Project")),
        UiAction("asset-import",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Import Asset")),
        UiAction("project-save",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Save Project")),
        UiAction("project-copy",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Copy Project")),
        UiAction("project-export",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Export Project")),
        UiAction("project-properties",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Project Properties")),
};
