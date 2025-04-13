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

    void resizeEvent(QResizeEvent *event);
    void slotTimer();
    void brushSizeCanged();

public:
    GraphicEditor(QWidget *parent = nullptr);
    ~GraphicEditor();
};

#endif // GRAPHICEDITOR_H
