#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H

#include <vector>
#include <QFile>

// A ProjectFile has layers, objects, and linked assets
// A ProjectFile can be exported / imported to/from a file.
class ProjectFile {
public:
    ProjectFile();
    ~ProjectFile() = default;

    static ProjectFile fromFile(QFile*);
    QFile* getFile();

    void linkAsset(QFile*);
    void removeAsset(QFile*);

private:
    // Main tree of children (objects)

    // Linked files (images, SVG, video, audio...)
    std::vector<QFile*> linkedAssets;
};

#endif // PROJECT_FILE_H
