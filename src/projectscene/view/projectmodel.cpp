#include "projectmodel.h"

using namespace app::projectscene;

ProjectModel::ProjectModel(QObject* parent)
        : QObject(parent) {};

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
