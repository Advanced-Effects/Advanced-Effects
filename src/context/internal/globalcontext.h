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
#ifndef MU_CONTEXT_GLOBALCONTEXT_H
#define MU_CONTEXT_GLOBALCONTEXT_H

#include "../iglobalcontext.h"

namespace mu::context {

using namespace glaxnimate::model;

class GlobalContext : public IGlobalContext
{
public:
    GlobalContext();

    Document* currentProjectFile() override;
    void setCurrentProjectFile(Document* document) override;

signals:
        void currentProjectFileChanged(Document* document) override;

private:
        QList<Document> m_openProjects;
        Document* m_currentProjectFile = nullptr;
};

}

#endif // MU_CONTEXT_GLOBALCONTEXT_H
