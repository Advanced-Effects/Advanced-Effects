#pragma once

#include <QQuickPaintedItem>
#include <QPainter>

#include "async/asyncable.h"

namespace app::projectscene {

class KeysView : public QQuickPaintedItem, public muse::async::Asyncable {
public:
        explicit KeysView(QQuickItem* parent = nullptr);
        ~KeysView() = default;

        void paint(QPainter* painter) override;
};

};
