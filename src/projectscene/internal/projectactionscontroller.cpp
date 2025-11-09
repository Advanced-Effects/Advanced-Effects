#include "projectactionscontroller.h"

using namespace app::projectscene;

void ProjectActionController::init() {
        dispatcher()->reg(this, "project-new", this, &ProjectActionController::newProject);
        dispatcher()->reg(this, "project-open", this, &ProjectActionController::openProject);
        dispatcher()->reg(this, "project-close", this, &ProjectActionController::closeProject);
};

void ProjectActionController::newProject() {
        interactive()->open("app://new");
};

void ProjectActionController::openProject() {};

void ProjectActionController::closeProject() {};

void ProjectActionController::importAsset() {};
