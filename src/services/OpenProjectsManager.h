#pragma once

#include <vector>
#include <QObject>
#include <QQmlEngine>
#include <QFile>

#include "library/ProjectFile/ProjectFile.h"

class OpenProjectsManager : public QObject {
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

public:
    static OpenProjectsManager &getInstance();

    std::vector<ProjectFile*> currentlyOpenProjects;

    ProjectFile* addFileAsProject(QFile*);
    void removeFileFromProjects(QFile*);

    // You can ignore this code below here
private:
    OpenProjectsManager(QObject *parent = nullptr);
    static OpenProjectsManager sInstance;

    // We delete these constructors here because this class
    // Is a Singleton
    OpenProjectsManager(const OpenProjectsManager&) = delete;
    OpenProjectsManager(OpenProjectsManager&&) = delete;
    OpenProjectsManager& operator=(const OpenProjectsManager&) = delete;
    OpenProjectsManager& operator=(OpenProjectsManager&&) = delete;
};
