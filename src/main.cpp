
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

/* ************************************************************************** */

int main(int argc, char *argv[])
{
    // Hacks ///////////////////////////////////////////////////////////////////

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

    // Force OpenGL for Qt WebEngine or the MapLibre plugin
    //qputenv("QSG_RHI_BACKEND", "opengl");

    // DEBUG ///////////////////////////////////////////////////////////////////

    //qputenv("QSG_INFO", "1");               // print Qt Scene Graph info
    //qputenv("QT_QPA_EGLFS_DEBUG", "1");     // print Qt Platform Abstraction EGL debug info
    //qputenv("QT_DEBUG_PLUGINS", "1");       // print Qt plugins info

    // Force QtQuick components style? // Some styles are only available on target OS
    // Basic // Fusion // Imagine // macOS // iOS // Material // Universal // Windows
    //QQuickStyle::setStyle("Universal");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/");
    engine.addImportPath(":/Advanced-Effects");
    engine.load(QUrl(QStringLiteral("qrc:/appshell/qml/Main.qml")));

    //qDebug() << engine.importPathList();
    //QDirIterator qrc(":", QDirIterator::Subdirectories);
    //while(qrc.hasNext()) { qWarning() << qrc.next(); }

    if (engine.rootObjects().isEmpty())
    {
        qWarning() << "Cannot init QmlApplicationEngine!";
        return EXIT_FAILURE;
    }

#if !defined(Q_OS_ANDROID) && !defined(Q_OS_IOS) // desktop section

    // QQuickWindow must be valid at this point
    QQuickWindow *window = qobject_cast<QQuickWindow *>(engine.rootObjects().value(0));
    if (!window) return EXIT_FAILURE;

#if defined(Q_OS_MACOS)
    // macOS dock
    MacOSDockHandler *dockIconHandler = MacOSDockHandler::getInstance();
    QObject::connect(dockIconHandler, &MacOSDockHandler::dockIconClicked, window, &QQuickWindow::show);
    QObject::connect(dockIconHandler, &MacOSDockHandler::dockIconClicked, window, &QQuickWindow::raise);
#endif

#endif // desktop section

    return app.exec();
}

/* ************************************************************************** */
