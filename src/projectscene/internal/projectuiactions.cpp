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
        UiAction("file-new",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "New Project")),
        UiAction("file-open",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Open Project")),
        UiAction("file-import",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Import Asset")),
        UiAction("file-save",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Save Project")),
        UiAction("file-copy",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Copy Project")),
        UiAction("file-export",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Export Project")),
        UiAction("file-properties",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Project Properties")),
};
