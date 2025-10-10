#include "applicationcanvas.h"

using namespace app::appshell;

ApplicationCanvas::ApplicationCanvas(QQuickItem *parent) : QQuickFramebufferObject(parent) {};

QQuickFramebufferObject::Renderer *ApplicationCanvas::createRenderer() const {
        return new Renderer;
};

void ApplicationCanvas::Renderer::render() {
        auto fbo = framebufferObject();
        if (!fbo) return;

        fbo->bind();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        fbo->release();
        update();
};

QOpenGLFramebufferObject *ApplicationCanvas::Renderer::createFramebufferObject(const QSize &size) {
        return new QOpenGLFramebufferObject(size);
};
