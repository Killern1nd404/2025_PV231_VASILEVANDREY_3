#include "PaintScene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    addEllipse(event->scenePos().x() - (int)(brush_size/2), event->scenePos().y() - (int)(brush_size/2), brush_size, brush_size, QPen(Qt::NoPen),QBrush(Qt::red));
    previous_point = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    addLine(previous_point.x(), previous_point.y(), event->scenePos().x(), event->scenePos().y(), QPen(Qt::red, brush_size, Qt::SolidLine, Qt::RoundCap));
    previous_point = event->scenePos();
}

void PaintScene::changeBrushSize(int size) {
    brush_size = size;
}
