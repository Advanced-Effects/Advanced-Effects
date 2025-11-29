#include "projectmodel.h"

using namespace app::projectscene;

ProjectModel::ProjectModel(QObject* parent)
        : QStringListModel(parent) {};

void ProjectModel::init() {
        connectFileSignals();
};

void ProjectModel::connectFileSignals() {
        //projectFiles()->openProjectsChanged.onNotify(this, []() {});
};

void ProjectModel::newProject(QString fileName,
                              int width,
                              int height,
                              int fps)
{
        projectFiles()->createAndOpenProject(fileName.toStdString(),
                                             width,
                                             height,
                                             fps);
};
