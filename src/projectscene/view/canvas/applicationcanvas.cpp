#include "applicationcanvas.h"

#include <exception>
#include <optional>

#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLContext>

#include "include/core/SkImageInfo.h"
#include "include/core/SkSurfaceCharacterization.h"

#include "include/gpu/GrTypes.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/gl/GrGLTypes.h"
#include "include/gpu/GrContext.h"
#include "include/gpu/GrBackendSurface.h"

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

void ApplicationCanvas::Renderer::performSkiaDraw() {
        if (!m_skia_canvas) return;

        auto projectFile = globalContext()->currentProjectFile();
        if (!projectFile) return;

        //auto composition = projectFile->current_comp();
        //auto rootNode = composition->docnode_parent();
        //rootNode->on_paint_skia(m_skia_canvas, ...);
};

// Create a SkSurface from an OpenGL FramebufferObject
// (Usually, our canvas)
sk_sp<SkSurface> ApplicationCanvas::Renderer::createSkiaSurfaceForFBO(QOpenGLFramebufferObject *fbo,
								      int width,
								      int height) {
	SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);

	m_glInterface = GrGLMakeNativeInterface();
	const GrContextOptions& grOptions = GrContextOptions();
	m_grContext = GrContext::MakeGL(m_glInterface, grOptions);
    
	GrGLFramebufferInfo fbInfo;
	fbInfo.fFBOID = fbo->handle();
	fbInfo.fFormat = GL_RGBA8;

	GrBackendRenderTarget backendRT(fbo->width(), fbo->height(),
					0, /* sample count */
					0, /* stencil bits*/
					fbInfo);
	
	return SkSurface::MakeFromBackendRenderTarget(
        	m_grContext.get(),
		backendRT,
		kBottomLeft_GrSurfaceOrigin,
		kRGBA_8888_SkColorType,
		nullptr, // optional color space
		nullptr // optional color surface
    	);
};

std::optional<std::monostate> ApplicationCanvas::Renderer::initSkia(QOpenGLFramebufferObject *fbo,
								    int width,
								    int height) {
        m_skia_surface = createSkiaSurfaceForFBO(fbo, width, height);
	if (!m_skia_surface) {
		// error: skia surface couldn't be created
		return std::nullopt;
	}
        m_skia_canvas = m_skia_surface->getCanvas();

	// success!
	return std::monostate();
};

QOpenGLFramebufferObject *ApplicationCanvas::Renderer::createFramebufferObject(const QSize &size) {
        auto fbo = new QOpenGLFramebufferObject(size);
        // Link skia to OpenGL Framebuffer Object
        auto result = initSkia(fbo, size.width(), size.height());

	auto hasSuccess = result.has_value();
	if (hasSuccess) return fbo;

	throw std::runtime_error("Unknown skia initalization error (SkSurface creation returned a nullptr)");
};
