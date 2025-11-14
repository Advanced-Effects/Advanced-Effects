#include "projectfilescontroller.h"

#include <QFile>

#include "glax_core/model/assets/assets.hpp"
#include "glax_core/io/base.hpp"

#include "glax_core/io/glaxnimate/glaxnimate_format.hpp"
#include "glax_core/io/aep/aep_format.hpp"

using namespace app::projectscene;
using namespace glaxnimate::io::glaxnimate;
using namespace glaxnimate::io;

void ProjectFilesController::addProject(std::shared_ptr<Document> document) {
        m_openProjects.append(document);
};

void ProjectFilesController::removeProject(std::shared_ptr<Document> document) {};

std::shared_ptr<Document> ProjectFilesController::importProject(QUrl fileUrl) {
        auto fileName = fileUrl.toLocalFile();
        auto documentToReturn = std::make_shared<Document>(fileName);

        // Select project importer to use
        ImportExport *import = GlaxnimateFormat::instance();
        if (!import->can_handle(ImportExport::Direction::Import)) return nullptr;

        // Open file
        auto file = QFile(fileName);

        // Actually import the file
        import->open(file, fileName, documentToReturn.get(), QVariantMap());

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
