#include "zoomablegraphicsview.h"

ZoomableGraphicsView::ZoomableGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);

     minScaleFactor = 0.2;
    maxScaleFactor = 11.0;

    // The image
    QPixmap image("C:/Users/Fawzy/OneDrive - YAT learning Solutions/Desktop/test test big.jpg");
    if (image.isNull()) {
        qDebug() << "Failed to load image";
        return;
    }

    pixmapItem = new QGraphicsPixmapItem(image);
    scene->addItem(pixmapItem);

    scene->setSceneRect(image.rect());

    // Set the scene for the graphics view
    setScene(scene);

    // Set rendering hints
    setRenderHint(QPainter::Antialiasing, true);
    setRenderHint(QPainter::SmoothPixmapTransform, true);

    // Enable mouse tracking to receive mouse move events even when no buttons are pressed
    setMouseTracking(true);

    // Set transformation anchor to ensure zoom is centered around the mouse cursor
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

/*void ZoomableGraphicsView::wheelEvent(QWheelEvent* event)
{
    // Zoom in/out with the mouse wheel
    const qreal scaleFactor = 1.2;
    if (event->angleDelta().y() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zoom out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}*/

