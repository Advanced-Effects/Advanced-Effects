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
#ifndef MU_CONTEXT_IGLOBALCONTEXT_H
#define MU_CONTEXT_IGLOBALCONTEXT_H

#include <QList>

#include "async/notification.h"
#include "modularity/imoduleinterface.h"

#include "glax_core/model/document.hpp"

namespace mu::context {

using namespace glaxnimate::model;

class IGlobalContext : MODULE_EXPORT_INTERFACE
{
        INTERFACE_ID(mu::context::IGlobalContext)

public:
        virtual ~IGlobalContext() = default;

        virtual Document* currentProjectFile() = 0;
        virtual void setCurrentProjectFile(Document* document) = 0;

signals:
        virtual void currentProjectFileChanged(Document*) = 0;
};
}

#endif // MU_CONTEXT_IGLOBALCONTEXT_H
