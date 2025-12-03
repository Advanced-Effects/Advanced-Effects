#include "applicationcanvas.h"

#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>

#include "include/core/SkImageInfo.h"

#include "glax_core/model/assets/composition.hpp"
#include "include/gpu/GrTypes.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/GrContext.h"

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

sk_sp<SkSurface> createSkiaSurfaceForFBO(GLuint fbo, int width, int height) {
    // Create Skia surface
    SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);

    sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
    const GrContextOptions& grOptions = GrContextOptions();
    auto grContext = GrContext::MakeGL(interface, grOptions);
    const GrBackendTexture& backendTexture = GrBackendTexture();

    auto colorType = SkColorSpace::MakeSRGB();
    const SkSurfaceProps* surfaceOptions = new SkSurfaceProps(0, kUnknown_SkPixelGeometry);

    return SkSurface::MakeFromBackendTexture(
        grContext.get(),
        backendTexture,
        kTopLeft_GrSurfaceOrigin,
        /* Sample count */ 1,
        kUnknown_SkColorType,
        colorType,
        surfaceOptions,
        nullptr,
        nullptr
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
