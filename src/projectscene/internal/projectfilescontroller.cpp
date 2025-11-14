#include "projectfilescontroller.h"

#include <QFile>

#include "glax_core/model/assets/assets.hpp"
#include "glax_core/io/base.hpp"
#include "io/glaxnimate/glaxnimate_format.hpp"

using namespace app::projectscene;
using namespace glaxnimate::io;

void ProjectFilesController::addProject(std::shared_ptr<Document> document) {
        m_openProjects.append(document);
};

void ProjectFilesController::removeProject(std::shared_ptr<Document> document) {};

std::shared_ptr<Document> ProjectFilesController::importProject(QUrl fileUrl) {
        auto documentToReturn = std::make_shared<Document>(fileUrl.toLocalFile());

        // Select project importer to use
        auto fileExtension = fileUrl.fileName();
        ImportExport *import = nullptr;
        if (!import->can_handle(ImportExport::Direction::Import)) return nullptr;

        // Open file
        auto file = QFile(fileUrl.toLocalFile());

        // Actually import the file
        import->open(file, fileUrl.toLocalFile(), documentToReturn.get(), QVariantMap());

        // And add it to project list and return
        addProject(documentToReturn);
        return documentToReturn;
};

std::shared_ptr<Document> ProjectFilesController::createAndOpenProject(std::string fileName,
                                                                       std::string sceneName,
                                                                       int width, int height,
                                                                       int fps) {
        auto document = std::make_shared<Document>();

        document->assets()->add_comp_no_undo();

        addProject(document);
        return document;
};
