#include "toolselectionmodel.h"

namespace app::appshell {

using namespace muse::uicomponents;

ToolSelectionModel::ToolSelectionModel(QObject* parent)
        : AbstractToolBarModel(parent) {};

void ToolSelectionModel::load() {
        ToolBarItemList items = getToolBarItems();

        setItems(items);

        AbstractToolBarModel::load();
};

ToolBarItemList ToolSelectionModel::getToolBarItems() {
        ToolBarItemList items {
                makeItem("selection-tool")
        };

        return items;
};

bool ToolSelectionModel::isInputAllowed() const {
        return false;
};

};
