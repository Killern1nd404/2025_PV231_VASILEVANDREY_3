#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QResizeEvent>
#include "PaintScene.h"
#include "ui_GraphicEditor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GraphicEditor;
}
QT_END_NAMESPACE

class GraphicEditor : public QMainWindow
{
    Q_OBJECT
    Ui::GraphicEditor *ui;
    QTimer *timer;
    PaintScene *scene;
    //int brush_color[3] = {0, 0, 0};

    void resizeEvent(QResizeEvent *event);
    void slotTimer();
    void brushSizeCanged();
    void setWhiteColor();
    void setBlackColor();
    void setRedColor();
    void setGreenColor();
    void setBlueColor();
    void setOrangeColor();
    void setBrownColor();
    void setYellowColor();
    void setPurpleColor();

public:
    GraphicEditor(QWidget *parent = nullptr);
    ~GraphicEditor();
};

#endif // GRAPHICEDITOR_H
