#pragma once

#include <memory>

#include "modularity/ioc.h"
#include "glax_core/model/document.hpp"

namespace app::projectscene {

using namespace glaxnimate::model;

class IProjectFilesController : public Injectable {
public:
        virtual ~IProjectFilesController() = default;

        virtual void addProject(std::shared_ptr<Document> document) = 0;
        virtual void removeProject(std::shared_ptr<Document> document) = 0;
};

}
