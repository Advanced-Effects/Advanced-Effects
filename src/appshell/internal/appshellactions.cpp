/// This file is used to register the application's actions
/// (Think of Gtk.Action, godot signals...)
///
/// The ones that are declared here are the ones for the
/// main application menu. (m_actions)
/// - They are used in appshell/view/appmenumodel.cpp
/// - In order to give actions a real functionality, they are declared
///   in appshell actions controller.

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
        UiAction("quit",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Quit")),
        // Edit menu
        UiAction("edit-copy",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Copy")),
        UiAction("edit-paste",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Paste")),
        UiAction("edit-cut",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Cut")),
        UiAction("edit-undo",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Undo")),
        UiAction("edit-redo",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Redo")),
        UiAction("open-preferences",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Preferences")),
        // Composition menu
        UiAction("composition-new",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "New Composition")),
        // Layer menu
        UiAction("layer-new",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "New Layer")),
        UiAction("layer-remove",
                UiCtxProjectOpened,
                muse::shortcuts::CTX_PROJECT_OPENED,
                TranslatableString("action", "Delete Layer")),
        // View menu
        UiAction("view-fullscreen",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Fullscreen")),
        // Window menu
        UiAction("window-maximize",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Maximize Window")),
        UiAction("window-minimize",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Minimize Window")),
        UiAction("window-close",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Close Window")),
        // Help menu
        UiAction("about-qt",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "About Qt")),
        UiAction("about-app",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "About")),
};
