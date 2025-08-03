/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-Studio-CLA-applies
 *
 * MuseScore Studio
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore Limited
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "uicontextresolver.h"

#include "diagnostics/diagnosticutils.h"

#include "shortcutcontext.h"

#include "muse_framework_config.h"

#include "log.h"

using namespace mu::context;
using namespace muse;
using namespace muse::ui;

static const muse::Uri HOME_PAGE_URI("musescore://home");
static const muse::Uri NOTATION_PAGE_URI("musescore://notation");

static const QString NOTATION_NAVIGATION_PANEL("ScoreView");

void UiContextResolver::init()
{
}

void UiContextResolver::notifyAboutContextChanged()
{
    m_currentUiContextChanged.notify();
}

UiContext UiContextResolver::currentUiContext() const
{
    TRACEFUNC;
    Uri currentUri = interactive()->currentUri().val;

#ifdef MUSE_MODULE_DIAGNOSTICS
    currentUri = diagnostics::diagnosticCurrentUri(interactive()->stack());
#endif

    if (currentUri == HOME_PAGE_URI) {
        return context::UiCtxHomeOpened;
    }

    if (currentUri == NOTATION_PAGE_URI) {
        INavigationPanel* activePanel = navigationController()->activePanel();
        if (activePanel) {
            if (activePanel->name() == NOTATION_NAVIGATION_PANEL) {
                return context::UiCtxProjectFocused;
            }
        }

        return context::UiCtxProjectOpened;
    }

    return context::UiCtxUnknown;
}

bool UiContextResolver::match(const muse::ui::UiContext& currentCtx, const muse::ui::UiContext& actCtx) const
{
    if (actCtx == context::UiCtxAny) {
        return true;
    }

    return currentCtx == actCtx;
}

bool UiContextResolver::matchWithCurrent(const UiContext& ctx) const
{
    if (ctx == muse::ui::UiCtxAny) {
        return true;
    }

    UiContext currentCtx = currentUiContext();
    return match(currentCtx, ctx);
}

muse::async::Notification UiContextResolver::currentUiContextChanged() const
{
    return m_currentUiContextChanged;
}

bool UiContextResolver::isShortcutContextAllowed(const std::string& scContext) const
{
    return true;
}
