#pragma once

#include "iprojectfilescontroller.h"

#include <QWidget>
#include <QListView>

namespace app::projectscene {

class ProjectModel : public QListView {
        Q_OBJECT
        INJECT(IProjectFilesController, projectFiles)

public:
        explicit ProjectModel(QWidget* parent = nullptr);
        ~ProjectModel() = default;

        void init();

        Q_INVOKABLE void newProject(QString fileName,
                                    int width,
                                    int height,
                                    int fps);

        // Signals
        void connectFileSignals();
};

}
