#pragma once

#include "uicomponents/view/abstractmenumodel.h"

#include "modularity/ioc.h"

namespace app::appshell {

class ToolSelectionModel : public muse::uicomponents::AbstractMenuModel {
        Q_OBJECT

        Q_PROPERTY(bool isInputAllowed READ isInputAllowed NOTIFY isInputAllowedChanged)
public:
        ToolSelectionModel(QObject* parent = nullptr);
        ~ToolSelectionModel() = default;

        Q_INVOKABLE void load() override;

        bool isInputAllowed() const;

signals:
        void isInputAllowedChanged();
private:
        muse::uicomponents::MenuItemList getMenuItems();
};

};
