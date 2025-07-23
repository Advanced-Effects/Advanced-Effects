#include "appmenumodel.h"

namespace ae::appshell {

AppMenuModel::AppMenuModel(QObject *parent) : muse::uicomponents::AbstractMenuModel(parent) {};

void AppMenuModel::load() {};

bool AppMenuModel::isGlobalMenuAvailable() {
    return false;
};


};
