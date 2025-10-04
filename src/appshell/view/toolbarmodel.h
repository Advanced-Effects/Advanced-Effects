#pragma once

#include "uicomponents/view/abstracttoolbarmodel.h"

#include "modularity/ioc.h"

namespace app::appshell {

// ToolBarModel is the skeleton of the ToolBar right above the Canvas.
//
// It comes from the class AbstractToolBarModel,
// and loads the different menus such as the ToolInputBar
// makeItem("tool-input") - for example.
//
// Menus like "tool-input" are also normal Actions - which are registered in
// `NotationUiActions` and `NotationActionController`.
class ToolBarModel : public muse::uicomponents::AbstractToolBarModel {
        Q_OBJECT
public:
        ToolBarModel(QObject* parent = nullptr);
        ~ToolBarModel() = default;

        Q_INVOKABLE void load() override;
};

};
