#include "toolbarmodel.h"

namespace app::projectscene {

using namespace muse::uicomponents;

ToolBarModel::ToolBarModel(QObject* parent)
        : AbstractToolBarModel(parent) {};

void ToolBarModel::load() {
        ToolBarItemList items {
                makeItem("tool-input")
        };
        setItems(items);

        AbstractToolBarModel::load();
};

};
