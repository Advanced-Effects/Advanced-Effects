#include "appshellactions.h"

#include "modularity/ioc.h"
#include "ui/uiaction.h"
#include "shortcuts/shortcutcontext.h"
#include "types/translatablestring.h"

using namespace app::appshell;
using namespace muse;
using namespace muse::ui;
using namespace muse::actions;


AppshellUiActions::AppshellUiActions(
        std::shared_ptr<AppshellActionController> controller,
        const muse::modularity::ContextPtr& iocCtx
) : muse::Injectable(iocCtx), m_controller(controller) {};

const UiActionList& AppshellUiActions::actionsList() const
{
    return m_actions;
}

bool AppshellUiActions::actionEnabled(const UiAction& act) const
{
    if (!m_controller->canReceiveAction(act.code)) {
        return false;
    }

    return true;
}

bool AppshellUiActions::actionChecked(const UiAction&) const
{
    return false;
}

async::Channel<ActionCodeList> AppshellUiActions::actionEnabledChanged() const
{
    return m_actionEnabledChanged;
}

async::Channel<ActionCodeList> AppshellUiActions::actionCheckedChanged() const
{
    return m_actionCheckedChanged;
}

const UiActionList AppshellUiActions::m_actions = {
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
        UiAction("quit",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Quit")),
};
