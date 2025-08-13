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
#include "actions/iactionsdispatcher.h"
#include "context/iglobalcontext.h"
#include "extensions/iextensionsprovider.h"
#include "global/iglobalconfiguration.h"
#ifdef MUSE_MODULE_MUSESAMPLER
#include "musesampler/imusesamplerinfo.h"
#endif
#include "ui/imainwindow.h"
#include "ui/inavigationcontroller.h"
#include "ui/iuiactionsregister.h"
#include "ui/iuiconfiguration.h"
#include "update/iupdateconfiguration.h"
#include "workspace/iworkspacemanager.h"

#include "internal/iappmenumodelhook.h"

namespace app::appshell {
class AppMenuModel : public muse::uicomponents::AbstractMenuModel
{
    Q_OBJECT

public:
    muse::Inject<IAppMenuModelHook> appMenuModelHook = { this };
    muse::Inject<mu::context::IGlobalContext> globalContext = { this };
    muse::Inject<muse::IGlobalConfiguration> globalConfiguration = { this };
    muse::Inject<muse::actions::IActionsDispatcher> actionsDispatcher = { this };
    muse::Inject<muse::extensions::IExtensionsProvider> extensionsProvider = { this };
#ifdef MUSE_MODULE_MUSESAMPLER
    muse::Inject<muse::musesampler::IMuseSamplerInfo> museSamplerInfo = { this };
#endif
    muse::Inject<muse::ui::IMainWindow> mainWindow = { this };
    muse::Inject<muse::ui::INavigationController> navigationController = { this };
    muse::Inject<muse::ui::IUiActionsRegister> uiActionsRegister = { this };
    muse::Inject<muse::ui::IUiConfiguration> uiConfiguration = { this };
    muse::Inject<muse::update::IUpdateConfiguration> updateConfiguration = { this };
    muse::Inject<muse::workspace::IWorkspaceManager> workspacesManager = { this };

public:
    explicit AppMenuModel(QObject* parent = nullptr);

    Q_INVOKABLE void load() override;
    Q_INVOKABLE bool isGlobalMenuAvailable();

};
}
