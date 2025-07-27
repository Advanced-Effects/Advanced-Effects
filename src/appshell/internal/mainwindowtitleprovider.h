#pragma once

#include <QObject>
#include <QString>

namespace ae::appshell {

// This is simply an object that we use to set / get some
// MainWindow properties like Window title, the current open file path,
// or whether the current file is modified.
//
// This way, the QML AppWindow doesn't need to have any concrete implementation
// details of the app state. Other parts of the app simply set a title:
//
// ```cpp
// mainWindowTitleProvider->setTitle("Someopijosifdg");
// ```
//
// Then the QML AppWindow gets it and renders it:
//
// ```qml
// MainWindowTitleProvider { id: titleProvider}
// (...)
// title: titleProvider.title
// ```
class MainWindowTitleProvider : public QObject {
    Q_OBJECT

    /* == Makes properties accessible to QML code == */
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString filePath READ filePath NOTIFY filePathChanged)
    Q_PROPERTY(bool fileModified READ fileModified NOTIFY fileModifiedChanged)

public:
    explicit MainWindowTitleProvider(QObject *parent = nullptr);
    ~MainWindowTitleProvider() = default;

    // Loads the filePath, title, etc. from the app state into this object
    Q_INVOKABLE void load();

    /* == Getters == */

    QString title() const;
    QString filePath() const;
    bool fileModified() const;

    /* == Setters == */

    void setTitle(const QString& title);
    void setFilePath(const QString& filePath);
    void setFileModified(bool fileModified);

    /* == Signals == */
signals:
    void titleChanged(QString title);
    void filePathChanged(QString filePath);
    void fileModifiedChanged(bool fileModified);

private:
    QString _title;
    QString _filePath;
    bool _fileModified;
};

};
