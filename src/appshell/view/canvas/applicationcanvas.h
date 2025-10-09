#pragma once

#include <QQuickFramebufferObject>
#include <QOpenGLFramebufferObject>

namespace app::appshell {

class ApplicationCanvas : public QQuickFramebufferObject {
        Q_OBJECT
public:
        ApplicationCanvas(QQuickItem *parent = nullptr);
        ~ApplicationCanvas() = default;

public:
        ApplicationCanvas::Renderer *createRenderer() const override;

        class Renderer : public QQuickFramebufferObject::Renderer {
        public:
                // OpenGL rendering code goes here
                void render() override;

                QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
        };
};

};
