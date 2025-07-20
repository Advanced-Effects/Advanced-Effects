#pragma once

#include <vector>
#include <QObject>
#include <QQmlEngine>

#include "library/ProjectFile/ProjectFile.h"

namespace ae::services {

using namespace ae::library::ProjectFile;

class OpenProjectsManager : public QObject {
    Q_OBJECT
    QML_SINGLETON

public:
    OpenProjectsManager(QObject *parent = nullptr)
    : QObject(parent) {};
    ~OpenProjectsManager() = default;

    std::vector<ProjectFile*> currentlyOpenProjects;
};

};
