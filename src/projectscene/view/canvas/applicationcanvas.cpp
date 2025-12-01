#include "applicationcanvas.h"

#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>

#include "include/core/SkImageInfo.h"

#include "glax_core/model/assets/composition.hpp"

using namespace app::projectscene;

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

        performSkiaDraw();

        fbo->release();
        update();
};

std::unique_ptr<SkSurface> createSkiaSurfaceForFBO(GLuint fbo, int width, int height) {
    // Create Skia surface
    SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);
    auto backendTexture = SkGr::GetGLBackendTexture();

    return SkSurface::MakeFromBackendTexture(
        backendTexture,
        width,
        height,
        kTopLeft_GrSurfaceOrigin,
        /* Sample count */ 1,
        kPremul_SkAlphaType,
        nullptr // Do not use a direct pixel copying
    );
}

void ApplicationCanvas::Renderer::initSkia(GLuint fbo, int width, int height) {
        m_skia_surface = createSkiaSurfaceForFBO(fbo, width, height);
        m_skia_canvas = m_skia_surface->getCanvas();
};

void ApplicationCanvas::Renderer::performSkiaDraw() {
        if (!m_skia_canvas) return;

        auto projectFile = globalContext()->currentProjectFile();
        if (!projectFile) return;

        auto composition = projectFile->current_comp();
        auto rootNode = composition->docnode_parent();
        //rootNode->on_paint_skia(m_skia_canvas, ...);
};

QOpenGLFramebufferObject *ApplicationCanvas::Renderer::createFramebufferObject(const QSize &size) {
        auto fbo = new QOpenGLFramebufferObject(size);
        // Link skia to OpenGL Framebuffer Object
        initSkia(fbo->handle(), size.width(), size.height());

        return fbo;
};
