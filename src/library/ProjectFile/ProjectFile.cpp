#include "ProjectFile.h"

#include <exception>

ProjectFile::ProjectFile() {};

ProjectFile ProjectFile::fromFile(QFile*) {
    return ProjectFile();
};

QFile* ProjectFile::getFile() {
    return nullptr;
};

void ProjectFile::linkAsset(QFile*) {};
void ProjectFile::removeAsset(QFile*) {};
