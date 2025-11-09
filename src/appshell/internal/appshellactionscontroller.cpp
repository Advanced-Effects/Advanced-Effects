#include "appshellactionscontroller.h"

#include <QCoreApplication>

#include "types/val.h"

using namespace muse::actions;

namespace app::appshell {

void AppshellActionController::init()
{
        dispatcher()->reg(this, "quit", [this](const ActionData& args) {
                quitApplication();
                return true;
        });

        dispatcher()->reg(this, "open-preferences", this, &AppshellActionController::openPreferencesDialog);
}

void AppshellActionController::quitApplication() {
        QCoreApplication::exit();
};

void AppshellActionController::openPreferencesDialog() {
        interactive()->open("app://preferences");
};

}
