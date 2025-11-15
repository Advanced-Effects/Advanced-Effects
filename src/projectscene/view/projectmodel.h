#pragma once

#include "iprojectfilescontroller.h"
#include <QObject>

namespace app::projectscene {

class ProjectModel : public QObject {
        Q_OBJECT
        INJECT(IProjectFilesController, projectFiles)

public:
        ProjectModel(QObject* parent = nullptr);
        ~ProjectModel() = default;

        Q_INVOKABLE void newProject(QString fileName,
                                    int width,
                                    int height,
                                    int fps);
};

}
