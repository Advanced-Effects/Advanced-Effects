#include "toolselectionmodel.h"

namespace app::appshell {

using namespace muse::uicomponents;

ToolSelectionModel::ToolSelectionModel(QObject* parent)
        : AbstractMenuModel(parent) {};

void ToolSelectionModel::load() {
        MenuItemList items = getMenuItems();

        setItems(items);
        AbstractMenuModel::load();
};

MenuItemList ToolSelectionModel::getMenuItems() {
        MenuItemList items {
                makeMenuItem("selection-tool")
        };

        return items;
};

bool ToolSelectionModel::isInputAllowed() const {
        return false;
};

};
