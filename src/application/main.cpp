
#include <QtGlobal>
#include <QLibraryInfo>
#include <QVersionNumber>

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QStringLiteral>
#include <QUrl>
#include <QQmlContext>
#include <QQuickWindow>
#include <QQuickStyle>
#include <QSurfaceFormat>

#include <QDir>
#include <QDirIterator>

/* ************************************************************************** */


void logQtResourceDirectories(QQmlApplicationEngine engine) {
    qDebug() << engine.importPathList();
    QDirIterator qrc(":", QDirIterator::Subdirectories);
    while(qrc.hasNext()) { qWarning() << qrc.next(); }
};

void runHacks() {
    #if defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)
        // NVIDIA driver suspend&resume hack
        auto format = QSurfaceFormat::defaultFormat();
        format.setOption(QSurfaceFormat::ResetNotification);
        QSurfaceFormat::setDefaultFormat(format);
    #endif

    #if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
        // Qt 6.6+ mouse wheel hack
        qputenv("QT_QUICK_FLICKABLE_WHEEL_DECELERATION", "10000");
    #endif
};

int showWindowFromRootElement(QQmlApplicationEngine engine) {
    // only create window in desktop
#if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS)
    // QQuickWindow must be valid at this point
    QQuickWindow *window = qobject_cast<QQuickWindow *>(engine.rootObjects().value(0));
    if (!window) return EXIT_FAILURE;
#endif

    return 0;
}

void createMacOSDock() {
#if defined(Q_OS_MACOS)
    // macOS dock
    MacOSDockHandler *dockIconHandler = MacOSDockHandler::getInstance();
    QObject::connect(dockIconHandler, &MacOSDockHandler::dockIconClicked, window, &QQuickWindow::show);
    QObject::connect(dockIconHandler, &MacOSDockHandler::dockIconClicked, window, &QQuickWindow::raise);
#endif
};

int createApplication(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.loadFromModule("AdvancedEffects", "Main");

    // Comment this out for debugging:
    //logQtResourceDirectories(&engine);

    if (engine.rootObjects().isEmpty())
    {
        qWarning() << "Cannot init QmlApplicationEngine!";
        return EXIT_FAILURE;
    }

    int error = showWindowFromRootElement(&engine);
    if (error != 0) {
        return error;
    }

    createMacOSDock();
    return app.exec();
};

int main(int argc, char *argv[])
{
    runHacks();

    return createApplication(argc, argv);
}

/* ************************************************************************** */
