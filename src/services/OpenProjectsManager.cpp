#include "OpenProjectsManager.h"

OpenProjectsManager::OpenProjectsManager(QObject *parent)
: QObject(parent) {};

OpenProjectsManager& OpenProjectsManager::getInstance() {
    return sInstance;
}

ProjectFile *OpenProjectsManager::addFileAsProject(QFile* file) {
    /*ProjectFile *projectFile = new ProjectFile::fromFile(file);

    //currentlyOpenProjects.push_back(projectFile);

    return projectFile;*/
    return new ProjectFile();
};

void OpenProjectsManager::removeFileFromProjects(QFile* file) {

};
