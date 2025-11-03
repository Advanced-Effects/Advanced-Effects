#pragma once

#include <QStandardItemModel>

namespace app::projectscene {

class MockTreeModel : public QStandardItemModel {
        Q_OBJECT
public:
        MockTreeModel(QObject *parent = nullptr);
        ~MockTreeModel() = default;
};

}
