#pragma once

#include "../iprojectfilescontroller.h"

#include <QList>

using namespace app::projectscene;

class ProjectFilesController : public IProjectFilesController
                             , public Injectable {
public:
        ProjectFilesController(const modularity::ContextPtr& iocCtx)
                : Injectable(iocCtx) {};
        ~ProjectFilesController() = default;

        void addProject(std::shared_ptr<Document> document) override;
        void removeProject(std::shared_ptr<Document> document) override;

        std::shared_ptr<Document> importProject(QUrl fileUrl) override;
        std::shared_ptr<Document> createAndOpenProject(std::string fileName,
                                                       std::string sceneName,
                                                       int width, int height,
                                                       int fps) override;
private:
        QList<std::shared_ptr<Document>> m_openProjects;
};
