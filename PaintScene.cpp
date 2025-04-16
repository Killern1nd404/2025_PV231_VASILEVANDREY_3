#include "PaintScene.h"
#include <string>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (draw_mode == "BRUSH") {
        addEllipse(event->scenePos().x() - (int)(brush_size/2), event->scenePos().y() - (int)(brush_size/2), brush_size, brush_size, QPen(Qt::NoPen),QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])));
        previous_point = event->scenePos();
    } else if (draw_mode == "FILL") {
        addRect(0, 0, 800, 630, QPen(Qt::NoPen), QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])));
    } else {
        previous_point = event->scenePos();
    }
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (draw_mode == "BRUSH") {
        addLine(previous_point.x(), previous_point.y(), event->scenePos().x(), event->scenePos().y(), QPen(QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])), brush_size, Qt::SolidLine, Qt::RoundCap));
        previous_point = event->scenePos();
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (draw_mode == "RECT" || draw_mode == "ELLIPSE") {
        int start_x = min(previous_point.x(), event->scenePos().x());
        int start_y = min(previous_point.y(), event->scenePos().y());
        int h = max(previous_point.x(), event->scenePos().x()) - start_x;
        int w = max(previous_point.y(), event->scenePos().y()) - start_y;

        if (draw_mode == "RECT") {
            addRect(start_x, start_y, h, w, QPen(Qt::NoPen), QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])));
        } else {
            addEllipse(start_x, start_y, h, w, QPen(Qt::NoPen), QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])));
        }
    } else if (draw_mode == "LINE") {
        addLine(previous_point.x(), previous_point.y(), event->scenePos().x(), event->scenePos().y(), QPen(QBrush(QColor(brush_color[0], brush_color[1], brush_color[2])), brush_size, Qt::SolidLine, Qt::RoundCap));
    }
}

void PaintScene::changeBrushSize(int size) {
    brush_size = size;
}

void PaintScene::setColor(int r, int g, int b) {
    brush_color[0] = r;
    brush_color[1] = g;
    brush_color[2] = b;
}

void PaintScene::setDrawMode(string mode) {
    draw_mode = mode;
}
