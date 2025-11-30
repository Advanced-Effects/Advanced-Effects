#pragma once

#include "async/asyncable.h"
#include "iprojectfilescontroller.h"

#include <QObject>
#include <QStringListModel>

namespace app::projectscene {

using namespace muse::async;

class ProjectModel : public QStringListModel
                   , public Asyncable {
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
