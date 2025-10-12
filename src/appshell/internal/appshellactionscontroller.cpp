#include "appshellactionscontroller.h"

#include <QCoreApplication>

#include "types/val.h"

using namespace app::appshell;

void AppshellActionController::init()
{
        dispatcher()->reg(this, "quit", [this](const ActionData& args) {
                quitApplication();
                return true;
        });

        dispatcher()->reg(this, "open-preferences", [this](const ActionData& args) {
                openPreferencesDialog();
                return true;
        });
}

void AppshellActionController::quitApplication() {
        QCoreApplication::exit();
};

void AppshellActionController::openPreferencesDialog() {
        interactive()->open("app://preferences");
};
