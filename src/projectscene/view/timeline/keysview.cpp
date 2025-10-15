#include "keysview.h"

using namespace app::projectscene;

KeysView::KeysView(QQuickItem* parent) : QQuickPaintedItem(parent)
, m_theme(uiEngine()->theme()) {};

void KeysView::paint(QPainter *painter) {
        drawTimelineControls(painter);
};

void KeysView::drawTimelineControls(QPainter *painter)
{
        // Always draw the top Timeline thing where you
        // see the seconds that have passed and select current frame.
        // (Fixed to the top)

        auto size = painter->viewport();
        int controlsHeight = 32;

        painter->setPen(m_theme->backgroundSecondaryColor());
        painter->drawRect(size.left(), 0, size.right(), controlsHeight);
};
