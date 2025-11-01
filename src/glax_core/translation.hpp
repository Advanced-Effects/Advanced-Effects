#pragma once

#include <QString>
#include <QStringList>

namespace glaxnimate {

QString i18n(QString string, QString args, ...);

QString i18n(QString string);
QString kli18n(QString string, QString args, ...);
QString kli18n(QString string);

};
