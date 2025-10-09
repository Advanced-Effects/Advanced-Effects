#pragma once

#include <QQuickItem>

namespace app::appshell {

class ApplicationCanvas : public QQuickItem {
        Q_OBJECT
public:
        ApplicationCanvas(QQuickItem *parent = nullptr);
        ~ApplicationCanvas() = default;
};

};
