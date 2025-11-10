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

private:
        QList<std::shared_ptr<Document>> m_openProjects;
};
