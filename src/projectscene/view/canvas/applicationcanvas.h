#pragma once

#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>

#include "context/iglobalcontext.h"
#include "include/gpu/GrTypes.h"
#include "include/gpu/GrContext.h"
#include "include/core/SkSurface.h"
#include "include/core/SkCanvas.h"

#include "modularity/ioc.h"

namespace app::projectscene {

class ApplicationCanvas : public QQuickFramebufferObject {
        Q_OBJECT
public:
        ApplicationCanvas(QQuickItem *parent = nullptr);
        ~ApplicationCanvas() = default;

public:
        ApplicationCanvas::Renderer *createRenderer() const override;

        class Renderer : public QQuickFramebufferObject::Renderer
                       , public muse::Injectable {
        mu::Inject<mu::context::IGlobalContext> globalContext = { this };

        public:
                // OpenGL rendering code goes here
                void render() override;

                QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
        private:
		std::optional<std::monostate> initSkia(QOpenGLFramebufferObject *fbo,
                                                       int width,
                                                       int height);
		sk_sp<SkSurface> createSkiaSurfaceForFBO(QOpenGLFramebufferObject *fbo,
							 int width,
							 int height);

                void performSkiaDraw();
		
		sk_sp<const GrGLInterface> m_glInterface;
		sk_sp<GrContext> m_grContext;
                sk_sp<SkSurface> m_skia_surface;
                SkCanvas* m_skia_canvas;
        };
};

};
