#include "projectactionscontroller.h"

#include <QUrl>
#include <QString>

using namespace app::projectscene;
using namespace glaxnimate::model;

void ProjectActionController::init() {
        dispatcher()->reg(this, "project-new", this, &ProjectActionController::newProject);
        dispatcher()->reg(this, "project-open", this, &ProjectActionController::openProject);
        dispatcher()->reg(this, "project-close", this, &ProjectActionController::closeProject);
};

void ProjectActionController::newProject() {
        interactive()->open("app://new");
};

void ProjectActionController::openProject(const muse::actions::ActionData& args) {
        QUrl url = !args.empty() ? args.arg<QUrl>(0) : QUrl();

        openProject(std::make_shared<Document>(url));
};

void ProjectActionController::openProject(std::shared_ptr<glaxnimate::model::Document> document) {
        projectFiles()->addProject(document);
};

void ProjectActionController::closeProject() {};

void ProjectActionController::importAsset() {};
