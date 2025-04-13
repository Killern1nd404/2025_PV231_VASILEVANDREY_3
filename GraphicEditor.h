#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GraphicEditor;
}
QT_END_NAMESPACE

class GraphicEditor : public QMainWindow
{
    Q_OBJECT

public:
    GraphicEditor(QWidget *parent = nullptr);
    ~GraphicEditor();

private:
    Ui::GraphicEditor *ui;
};
#endif // GRAPHICEDITOR_H
