#include "PaintScene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    addEllipse(event->scenePos().x() - (int)(brush_size/2), event->scenePos().y() - (int)(brush_size/2), brush_size, brush_size, QPen(Qt::NoPen),QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])));
    previous_point = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    addLine(previous_point.x(), previous_point.y(), event->scenePos().x(), event->scenePos().y(), QPen(QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])), brush_size, Qt::SolidLine, Qt::RoundCap));
    previous_point = event->scenePos();
}

void PaintScene::changeBrushSize(int size) {
    brush_size = size;
}

void PaintScene::setColor(int r, int g, int b) {
    brush_color[0] = r;
    brush_color[1] = g;
    brush_color[2] = b;
}
