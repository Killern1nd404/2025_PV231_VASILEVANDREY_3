#include "GraphicEditor.h"
#include "./ui_GraphicEditor.h"

GraphicEditor::GraphicEditor(QWidget *parent) : QMainWindow(parent), ui(new Ui::GraphicEditor) {
    ui->setupUi(this);

    scene = new PaintScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &GraphicEditor::slotTimer);
    timer->start(100);

    connect(ui->brushSize, &QSpinBox::valueChanged, this, &GraphicEditor::brushSizeCanged);
}

GraphicEditor::~GraphicEditor()
{
    delete ui;
}

void GraphicEditor::slotTimer() {
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width()-20, ui->graphicsView->height()-200);
}

void GraphicEditor::brushSizeCanged() {
    scene->changeBrushSize(ui->brushSize->value());
}

void GraphicEditor::resizeEvent(QResizeEvent *event) {
    timer->start(100);
    QWidget::resizeEvent(event);
}
