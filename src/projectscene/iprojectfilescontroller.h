#pragma once

#include <memory>

#include "modularity/ioc.h"
#include "async/notification.h"

#include "glax_core/model/document.hpp"

namespace app::projectscene {

using namespace glaxnimate::model;

class IProjectFilesController : MODULE_EXPORT_INTERFACE {
        INTERFACE_ID(app::projectscene::IProjectFilesController)

public:
        virtual ~IProjectFilesController() = default;

        virtual void init() {};

        virtual void addProject(std::shared_ptr<Document> document) = 0;
        virtual void removeProject(std::shared_ptr<Document> document) = 0;

        virtual std::shared_ptr<Document> importProject(QUrl fileUrl) = 0;
        virtual std::shared_ptr<Document> createAndOpenProject(std::string fileName,
                                                               int width, int height,
                                                               int fps) = 0;
        // Signals
        muse::async::Notification openProjectsChanged;
};

}
