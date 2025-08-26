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
#pragma once

#include "uicomponents/view/abstractmenumodel.h"

#include "muse_framework_config.h"

#include "modularity/ioc.h"
#include "uicomponents/view/menuitem.h"

#include "ui/imainwindow.h"
#include "ui/inavigationcontroller.h"

namespace app::appshell {

using namespace muse::uicomponents;

class AppMenuModel : public muse::uicomponents::AbstractMenuModel
{
    Q_OBJECT

    muse::Inject<muse::ui::INavigationController> navigationController = { this };
public:
    explicit AppMenuModel(QObject* parent = nullptr);

    Q_INVOKABLE void load() override;

private:
        MenuItemList getMenuList();

        MenuItem* makeFileMenu();
        MenuItem* makeEditMenu();
        MenuItem* makeCompositionMenu();
        MenuItem* makeLayerMenu();
        MenuItem* makeEffectsMenu();
        MenuItem* makeViewMenu();
        MenuItem* makeWindowMenu();
        MenuItem* makeHelpMenu();
};
}
