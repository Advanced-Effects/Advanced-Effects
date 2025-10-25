#pragma once

#include <QObject>
#include <QString>

namespace app::appshell {

class PlatformDetails : public QObject {
        Q_OBJECT
public:
        PlatformDetails(QObject *parent = nullptr);
        ~PlatformDetails() = default;

        Q_INVOKABLE bool isWindows();
        Q_INVOKABLE bool isMac();
        Q_INVOKABLE bool isLinux();

private:
        const QString m_platformName;
};

}
