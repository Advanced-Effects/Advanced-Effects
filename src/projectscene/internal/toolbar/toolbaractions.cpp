/// This file is used to register the application's actions
/// (Think of Gtk.Action, godot signals...)
///
/// The ones that are declared here are the ones for the
/// main application menu. (m_actions)
/// - They are used in appshell/view/appmenumodel.cpp
/// - In order to give actions a real functionality, they are declared
///   in appshell actions controller.

#include "toolbaractions.h"

#include "modularity/ioc.h"
#include "ui/uiaction.h"
#include "shortcuts/shortcutcontext.h"
#include "types/translatablestring.h"
#include "ui/view/iconcodes.h"

#include "context/uicontext.h"
#include "context/shortcutcontext.h"

using namespace mu;
using namespace mu::context;
using namespace app::projectscene;
using namespace muse;
using namespace muse::ui;
using namespace muse::actions;


ToolBarUiActions::ToolBarUiActions(
        std::shared_ptr<ToolActionController> controller,
        const muse::modularity::ContextPtr& iocCtx
) : muse::Injectable(iocCtx), m_controller(controller) {};

const UiActionList& ToolBarUiActions::actionsList() const
{
    return m_actions;
};

bool ToolBarUiActions::actionEnabled(const UiAction& act) const
{
    if (!m_controller->canReceiveAction(act.code)) {
        return false;
    }

    return true;
};

bool ToolBarUiActions::actionChecked(const UiAction&) const
{
    return false;
};

async::Channel<ActionCodeList> ToolBarUiActions::actionEnabledChanged() const
{
    return m_actionEnabledChanged;
};

async::Channel<ActionCodeList> ToolBarUiActions::actionCheckedChanged() const
{
    return m_actionCheckedChanged;
};

const UiActionList ToolBarUiActions::m_actions = {
        UiAction("tool-input",
                mu::context::UiCtxProjectOpened,
                mu::context::CTX_NOTATION_OPENED,
                TranslatableString("action", "Selection Tool"),
                TranslatableString("action", "Select and modify existing objects."),
                IconCode::Code::ARROW_UP
        ),
        UiAction("select-tool",
                mu::context::UiCtxProjectOpened,
                mu::context::CTX_NOTATION_OPENED,
                TranslatableString("action", "Selection Tool"),
                TranslatableString("action", "Select and modify existing objects."),
                IconCode::Code::ARROW_UP
        )
};
