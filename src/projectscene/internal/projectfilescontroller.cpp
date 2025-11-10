#include "projectfilescontroller.h"

using namespace app::projectscene;

void ProjectFilesController::addProject(std::shared_ptr<Document> document) {
        m_openProjects->append(document);
};

void ProjectFilesController::removeProject(std::shared_ptr<Document> document) {};
