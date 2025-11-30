#include "projectmodel.h"

using namespace app::projectscene;

ProjectModel::ProjectModel(QObject* parent)
        : QStringListModel(parent) {};

void ProjectModel::init() {
        connectFileSignals();
};

void ProjectModel::connectFileSignals() {
        // When the project list is updated
        projectFiles()->openProjectsChanged.onNotify(this, [=]() {
                // Refill it
                auto projects = projectFiles()->projects();

                QStringList list;
                for (auto project : projects) {
                        list.append(project->filename());
                };

                setStringList(list);
        });
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
