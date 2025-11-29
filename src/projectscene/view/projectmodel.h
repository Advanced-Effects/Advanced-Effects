#pragma once

#include "iprojectfilescontroller.h"

#include <QObject>
#include <QStringListModel>

namespace app::projectscene {

class ProjectModel : public QStringListModel {
        Q_OBJECT
        INJECT(IProjectFilesController, projectFiles)

public:
        explicit ProjectModel(QObject* parent = nullptr);
        ~ProjectModel() = default;

        void init();

        Q_INVOKABLE void newProject(QString fileName,
                                    int width,
                                    int height,
                                    int fps);

        // Connects to IProjectsFileController to make sure
        // files there are also updated here
        void connectFileSignals();
};

}
