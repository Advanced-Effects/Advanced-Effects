#pragma once

#include "ui/iuiactionsmodule.h"
#include "modularity/ioc.h"
#include "ui/iuicontextresolver.h"

#include "appshellactionscontroller.h"

namespace app::appshell {

using namespace muse;

class AppshellUiActions
        : public ui::IUiActionsModule
        , public Injectable {
        muse::Inject<ui::IUiContextResolver> uicontextResolver = { this };

public:
        AppshellUiActions(std::shared_ptr<AppshellActionController> controller,
                          const muse::modularity::ContextPtr& iocCtx);

        const ui::UiActionList& actionsList() const override;

        bool actionEnabled(const ui::UiAction& act) const override;
        async::Channel<actions::ActionCodeList> actionEnabledChanged() const override;

        bool actionChecked(const ui::UiAction& act) const override;
        async::Channel<actions::ActionCodeList> actionCheckedChanged() const override;

private:
        static const ui::UiActionList m_actions;
        std::shared_ptr<AppshellActionController> m_controller;
        async::Channel<actions::ActionCodeList> m_actionEnabledChanged;
        async::Channel<actions::ActionCodeList> m_actionCheckedChanged;
};

};
