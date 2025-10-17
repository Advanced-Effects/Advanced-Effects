#pragma once

#include <QQuickPaintedItem>
#include <QPainter>

#include "async/asyncable.h"
#include "modularity/ioc.h"

#include "timelinecontext.h"
#include "ui/api/themeapi.h"
#include "ui/iuiengine.h"

using namespace mu;
using namespace muse::ui;
using namespace muse::api;

namespace app::projectscene {

class KeysView : public QQuickPaintedItem, public muse::async::Asyncable {
public:
        explicit KeysView(QQuickItem* parent = nullptr);
        ~KeysView() = default;

        void paint(QPainter* painter) override;

private:
        void drawTimelineControls(QPainter* painter);

        TimelineContext m_timelineContext;

        float mousePosition[2];
};

};
