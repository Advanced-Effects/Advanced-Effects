/*
 * SPDX-FileCopyrightText: 2019-2023 Mattia Basaglia <dev@dragon.best>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "app_info.hpp"

#include <QGuiApplication>
#include <KLocalizedString>

#include "application_info_generated.hpp"
#include "utils/trace.hpp"
#include "utils/tar.hpp"
#include "io/video/video_format.hpp"
#include "app/scripting/python/python_engine.hpp"

QString glaxnimate::AppInfo::name() const
{
    return i18n("Glaxnimate");
}

QString glaxnimate::AppInfo::slug() const
{
    return PROJECT_SLUG;
}

QString glaxnimate::AppInfo::version() const
{
    return PROJECT_VERSION;
}

QString glaxnimate::AppInfo::organization() const
{
    return PROJECT_SLUG;
}

QUrl glaxnimate::AppInfo::url_docs() const
{
    return QUrl(URL_DOCS);
}

QString glaxnimate::AppInfo::description() const
{
    return PROJECT_DESCRIPTION;
}
