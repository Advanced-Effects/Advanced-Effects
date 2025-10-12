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

AppMenuModel::AppMenuModel(QObject* parent)
    : AbstractMenuModel(parent)
{
}

void AppMenuModel::load()
{
    TRACEFUNC;

    MenuItemList items = getMenuList();
    setItems(items);

    AbstractMenuModel::load();
}

MenuItemList AppMenuModel::getMenuList() {
        MenuItemList items {
                makeFileMenu(),
                makeEditMenu(),
                makeCompositionMenu(),
                makeLayerMenu(),
                makeEffectsMenu(),
                makeViewMenu(),
                makeWindowMenu(),
                makeHelpMenu()
        };

        return items;
}

MenuItem* AppMenuModel::makeFileMenu() {
        MenuItemList items {
                makeMenuItem("file-new"),
                makeMenuItem("file-open"),
                makeMenuItem("file-import"),
                makeSeparator(),
                makeMenuItem("file-save"),
                makeMenuItem("file-copy"),
                makeMenuItem("file-export"),
                makeSeparator(),
                makeMenuItem("file-properties"),
                makeSeparator(),
                makeMenuItem("quit")
        };

        return makeMenu(TranslatableString("appshell/menu/file", "&File"), items, "menu-file");
}

MenuItem* AppMenuModel::makeEditMenu() {
        MenuItemList items {
                makeMenuItem("edit-copy"),
                makeMenuItem("edit-paste"),
                makeMenuItem("edit-cut"),
                makeSeparator(),
                makeMenuItem("edit-undo"),
                makeMenuItem("edit-redo"),
                makeSeparator(),
                makeMenuItem("open-preferences")
        };

        return makeMenu(TranslatableString("appshell/menu/edit", "&Edit"), items, "menu-edit");
};

MenuItem* AppMenuModel::makeCompositionMenu() {
        MenuItemList items {
                makeMenuItem("composition-new"),
        };

        return makeMenu(TranslatableString("appshell/menu/composition", "&Composition"), items, "menu-composition");
};

MenuItem* AppMenuModel::makeLayerMenu() {
        MenuItemList items {
                makeMenuItem("layer-new"),
                makeMenuItem("layer-remove"),
        };

        return makeMenu(TranslatableString("appshell/menu/layer", "&Layer"), items, "menu-layer");
};

MenuItem* AppMenuModel::submenuRasterEffects() {
        MenuItemList items {};

        return makeMenu(
                TranslatableString("appshell/menu/effects/raster", "&Raster effects"),
                items,
                "menu-effects-raster"
        );
};
MenuItem* AppMenuModel::submenuVectorEffects() {
        MenuItemList items {};

        return makeMenu(
                TranslatableString("appshell/menu/effects/vector", "&Vector effects"),
                items,
                "menu-effects-vector"
        );
};
MenuItem* AppMenuModel::submenuPathEffects() {
        MenuItemList items {};

        return makeMenu(
                TranslatableString("appshell/menu/effects/path", "&Path effects"),
                items,
                "menu-effects-path"
        );
};

MenuItem* AppMenuModel::makeEffectsMenu() {
        MenuItemList items {
                submenuRasterEffects(),
                submenuVectorEffects(),
                submenuPathEffects(),
        };

        return makeMenu(TranslatableString("appshell/menu/effects", "&Effects"), items, "menu-effects");
};

MenuItem* AppMenuModel::makeViewMenu() {
        MenuItemList items {
                makeMenuItem("view-fullscreen"),
        };

        return makeMenu(TranslatableString("appshell/menu/view", "&View"), items, "menu-view");
};

MenuItem* AppMenuModel::makeWindowMenu() {
        MenuItemList items {
                makeMenuItem("window-maximize"),
                makeMenuItem("window-minimize"),
                makeMenuItem("window-close"),
        };

        return makeMenu(TranslatableString("appshell/menu/window", "&Window"), items, "menu-window");
};

MenuItem* AppMenuModel::makeHelpMenu() {
        MenuItemList items {
                makeMenuItem("about-qt"),
                makeMenuItem("about-app"),
        };

        return makeMenu(TranslatableString("appshell/menu/help", "&Help"), items, "menu-help");
};
