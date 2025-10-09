#include "applicationcanvas.h"

using namespace app::appshell;

ApplicationCanvas::ApplicationCanvas(QQuickItem *parent) : QQuickFramebufferObject(parent) {};

QQuickFramebufferObject::Renderer *ApplicationCanvas::createRenderer() const {
        return new Renderer;
};

void ApplicationCanvas::Renderer::render() {};

QOpenGLFramebufferObject *ApplicationCanvas::Renderer::createFramebufferObject(const QSize &size) {
        return new QOpenGLFramebufferObject(size);
};
