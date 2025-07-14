#pragma once

#include <vector>
#include <QFile>

namespace ae::library::ProjectFile {

// A ProjectFile has layers, objects, and linked assets
// A ProjectFile can be exported / imported to/from a file.
class ProjectFile {
    ProjectFile();
    ~ProjectFile() = default;

    static ProjectFile fromFile(QFile*);
    QFile* toFile();

public:
    void linkAsset(QFile*);
    void removeAsset(QFile*);

private:
    // Main tree of children (objects)

    // Linked files (images, SVG, video, audio...)
    std::vector<QFile*> linkedAssets;
};

};
