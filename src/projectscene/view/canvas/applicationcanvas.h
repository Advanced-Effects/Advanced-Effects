#pragma once

#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>

#include "context/iglobalcontext.h"
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
                void initSkia(GLuint fbo,
                              int width,
                              int height);
                void performSkiaDraw();

                sk_sp<SkSurface> m_skia_surface;
                SkCanvas* m_skia_canvas;
        };
};

};
