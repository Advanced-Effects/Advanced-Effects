#pragma once

#include <vector>
#include <QObject>
#include <QQmlEngine>
#include <QJSValue>

#include "library/project_file/ProjectFile.h"

class OpenProjectsManager : public QObject {
    Q_OBJECT
    QML_SINGLETON

public:
    OpenProjectsManager(QJsValue id, QObject *parent = nullptr)
    : QObject(parent)
    , _symbol(std::move(id)) {};

    static OpenProjectsManager *create(QQmlEngine *qmlEngine, QJSEngine *) {
        return new OpenProjectsManager(qmlEngine->newSymbol(u"OpenProjectsManager"_s));
    };

    std::vector<ProjectFile> currentlyOpenProjects;

private:
    QJSValue _symbol;
};
