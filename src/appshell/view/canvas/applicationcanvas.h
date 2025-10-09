#pragma once

#include <QQuickWidget>

#include "openglwidget.h"

namespace app::appshell {

class ApplicationCanvas : public QQuickWidget {
        Q_OBJECT
public:
        ApplicationCanvas(QWidget *parent = nullptr);
        ~ApplicationCanvas() = default;
};

};
