#pragma once

#include "uicomponents/view/abstracttoolbarmodel.h"

#include "modularity/ioc.h"

namespace app::appshell {

// ToolSelectionModel is the skeleton of the tool selection bar,
// right above the Canvas.
//
// It comes from the class AbstractToolBarModel,
// and loads the different tools people can switch between
// makeItem("selection-tool") - for example.
class ToolSelectionModel : public muse::uicomponents::AbstractToolBarModel {
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
        muse::uicomponents::ToolBarItemList getMenuItems();
};

};
