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
#include "appmenumodel.h"

#include "types/translatablestring.h"

#include "log.h"

using namespace muse;
using namespace app::appshell;
using namespace muse::ui;
using namespace muse::uicomponents;
using namespace muse::workspace;
using namespace muse::actions;
using namespace muse::extensions;

static const ActionCode TOGGLE_UNDO_HISTORY_PANEL_CODE = "toggle-undo-history-panel";
static const QString VIEW_TOGGLE_UNDO_HISTORY_PANEL_ITEM_ID = "view/toggle-undo-history-panel";

static QString makeId(const ActionCode& actionCode, int itemIndex)
{
    return QString::fromStdString(actionCode) + QString::number(itemIndex);
}

AppMenuModel::AppMenuModel(QObject* parent)
    : AbstractMenuModel(parent)
{
}

void AppMenuModel::load()
{
    TRACEFUNC;
}

bool AppMenuModel::isGlobalMenuAvailable()
{
    return uiConfiguration()->isGlobalMenuAvailable();
}
