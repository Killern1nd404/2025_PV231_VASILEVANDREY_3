#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    QPointF previous_point;
    int brush_size = 5;
    int brush_color[3] = {0, 0, 0};

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

public:
    PaintScene(QObject *parent=nullptr);
    ~PaintScene();
    void changeBrushSize(int size);
    void setColor(int r, int g, int b);
};

#endif // PAINTSCENE_H
