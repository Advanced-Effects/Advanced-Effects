#include "mainwindowtitleprovider.h"

using namespace ae::appshell;

MainWindowTitleProvider::MainWindowTitleProvider(QObject *parent) {};

void MainWindowTitleProvider::load() {};

void MainWindowTitleProvider::setTitle(const QString& title) {
    _title = title;
    emit titleChanged(title);
};

void MainWindowTitleProvider::setFilePath(const QString& filePath) {
    _filePath = filePath;
    emit filePathChanged(filePath);
};

void MainWindowTitleProvider::setFileModified(bool fileModified) {
    _fileModified = fileModified;
    emit fileModifiedChanged(fileModified);
};

QString MainWindowTitleProvider::title() const {
    return _title;
}

QString MainWindowTitleProvider::filePath() const {
    return _filePath;
}

bool MainWindowTitleProvider::fileModified() const {
    return _fileModified;
}
