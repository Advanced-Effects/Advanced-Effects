#include <QDateTime>

namespace app::projectscene {

struct TimelineContext {
        float deplacement[2] = {};
        float scale = 1;

        QDateTime *duration = nullptr;
};

};
