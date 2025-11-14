#include "projectactionscontroller.h"

#include <QUrl>
#include <QString>
#include <QFileDialog>

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
        auto hasProvidedFile = !args.empty();
        if (hasProvidedFile) {
                QUrl url = args.arg<QUrl>(0);

                openProject(std::make_shared<Document>(url.toString()));
        }

        auto fileUrl = QFileDialog::getOpenFileUrl(nullptr,
                                                   "",
                                                   QUrl(),
                                                   "Glaxnimate project file (*.rawr);;\
                                                   After Effects file (*.aep)");

        return openProject(fileUrl);
};

void ProjectActionController::openProject(std::shared_ptr<Document> document) {
        projectFiles()->addProject(document);
};

void ProjectActionController::openProject(QUrl fileUrl) {
        projectFiles()->importProject(fileUrl);
};

void ProjectActionController::closeProject() {};

void ProjectActionController::importAsset() {};
