#include "toolselectionmodel.h"

namespace app::appshell {

using namespace muse::uicomponents;

ToolSelectionModel::ToolSelectionModel(QObject* parent)
        : AbstractToolBarModel(parent) {};

void ToolSelectionModel::load() {
        ToolBarItemList items {
                makeItem("tool-input")
        };
        setItems(items);

        AbstractToolBarModel::load();
};

};
