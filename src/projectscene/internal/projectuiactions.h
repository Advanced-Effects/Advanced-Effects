#pragma once

#include "ui/iuiactionsmodule.h"
#include "modularity/ioc.h"
#include "ui/iuicontextresolver.h"

#include "projectactionscontroller.h"

namespace app::projectscene {

using namespace muse;

class ProjectUiActions
        : public Injectable
        , public ui::IUiActionsModule
{
        Inject<ui::IUiContextResolver> uiContextResolver = { this };

public:
        ProjectUiActions(std::shared_ptr<ProjectActionController> controller,
                         const muse::modularity::ContextPtr& iocCtx);

        const ui::UiActionList& actionsList() const override;

        bool actionEnabled(const ui::UiAction& act) const override;
        async::Channel<actions::ActionCodeList> actionEnabledChanged() const override;

        bool actionChecked(const ui::UiAction& act) const override;
        async::Channel<actions::ActionCodeList> actionCheckedChanged() const override;

private:
        static const ui::UiActionList m_actions;
        std::shared_ptr<ProjectActionController> m_controller;
        async::Channel<actions::ActionCodeList> m_actionEnabledChanged;
        async::Channel<actions::ActionCodeList> m_actionCheckedChanged;

};

}
