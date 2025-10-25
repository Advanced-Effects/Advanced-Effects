#include "platformdetails.h"

#include <QGuiApplication>

using namespace app::appshell;

PlatformDetails::PlatformDetails(QObject* parent)
        : QObject(parent)
        , m_platformName(QGuiApplication::platformName()) {};

bool PlatformDetails::isWindows() {
        return false/*m_platformName == "windows"*/;
};
bool PlatformDetails::isMac() {
        return m_platformName == "cocoa";
};
bool PlatformDetails::isLinux() {
        return m_platformName == "wayland" || m_platformName == "xcb";
};
