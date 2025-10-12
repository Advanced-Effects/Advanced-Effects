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
        UiAction("quit",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Quit")),
        // Edit menu
        UiAction("edit-copy",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Copy")),
        UiAction("edit-paste",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Paste")),
        UiAction("edit-cut",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Cut")),
        UiAction("edit-undo",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Undo")),
        UiAction("edit-redo",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Redo")),
        UiAction("open-preferences",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "Preferences")),
        // Composition menu
        UiAction("composition-new",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "New Composition")),
        // Layer menu
        UiAction("layer-new",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
                TranslatableString("action", "New Layer")),
        UiAction("layer-remove",
                UiCtxAny,
                muse::shortcuts::CTX_ANY,
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
