#ifndef ZOOMABLEGRAPHICSVIEW_H
#define ZOOMABLEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QDebug>

class ZoomableGraphicsView : public QGraphicsView
{
public:
    ZoomableGraphicsView(QWidget* parent = nullptr);
    qreal minScaleFactor;
    qreal maxScaleFactor;
protected:
    void wheelEvent(QWheelEvent* event) override {
        // Zoom in/out with the mouse wheel
        const qreal scaleFactor = 1.2;
        qreal currentScaleFactor = transform().m11(); // assuming uniform scaling in x and y

        if (event->angleDelta().y() > 0) {
            // Zoom in, but check the scale limit
            if (currentScaleFactor < maxScaleFactor) {
                scale(scaleFactor, scaleFactor);
            }
        } else {
            // Zoom out, but check the scale limit
            if (currentScaleFactor > minScaleFactor) {
                scale(1.0 / scaleFactor, 1.0 / scaleFactor);
            }
        }

        // Enforce minimum scale factor
        currentScaleFactor = transform().m11();
        if (currentScaleFactor < minScaleFactor) {
            qreal correctionFactor = minScaleFactor / currentScaleFactor;
            scale(correctionFactor, correctionFactor);
        }

        // Enforce maximum scale factor
        currentScaleFactor = transform().m11();
        if (currentScaleFactor > maxScaleFactor) {
            qreal correctionFactor = maxScaleFactor / currentScaleFactor;
            scale(correctionFactor, correctionFactor);
        }
    }



private:
    QGraphicsScene* scene;
    QGraphicsPixmapItem* pixmapItem;
};

#endif // ZOOMABLEGRAPHICSVIEW_H
