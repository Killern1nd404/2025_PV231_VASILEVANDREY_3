#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QResizeEvent>
#include "PaintScene.h"
#include "ui_GraphicEditor.h"
#include "SmartPtr.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GraphicEditor;
}
QT_END_NAMESPACE

class GraphicEditor : public QMainWindow
{
    Q_OBJECT
    SmartPtr<Ui::GraphicEditor> ui;
    QTimer *timer;
    PaintScene *scene;

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
    void setBrushMode();
    void setRectMode();
    void setEllipseMode();
    void setLineMode();
    void setFillMode();
    void saveImage();
    void loadImage();

public:
    GraphicEditor(QWidget *parent = nullptr);
};

#endif // GRAPHICEDITOR_H
