#include "GraphicEditor.h"
#include "./ui_GraphicEditor.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>

GraphicEditor::GraphicEditor(QWidget *parent) : QMainWindow(parent), ui(new Ui::GraphicEditor) {
    ui->setupUi(this);

    scene = new PaintScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &GraphicEditor::slotTimer);
    timer->start(100);

    connect(ui->brushSize, &QSpinBox::valueChanged, this, &GraphicEditor::brushSizeCanged);
    connect(ui->setWhiteButton, &QPushButton::clicked, this, &GraphicEditor::setWhiteColor);
    connect(ui->setBlackButton, &QPushButton::clicked, this, &GraphicEditor::setBlackColor);
    connect(ui->setRedButton, &QPushButton::clicked, this, &GraphicEditor::setRedColor);
    connect(ui->setGreenButton, &QPushButton::clicked, this, &GraphicEditor::setGreenColor);
    connect(ui->setBlueButton, &QPushButton::clicked, this, &GraphicEditor::setBlueColor);
    connect(ui->setBrownButton, &QPushButton::clicked, this, &GraphicEditor::setBrownColor);
    connect(ui->setPurpleButton, &QPushButton::clicked, this, &GraphicEditor::setPurpleColor);
    connect(ui->setYellowButton, &QPushButton::clicked, this, &GraphicEditor::setYellowColor);
    connect(ui->setOrangeButton, &QPushButton::clicked, this, &GraphicEditor::setOrangeColor);
    connect(ui->brushButton, &QPushButton::clicked, this, &GraphicEditor::setBrushMode);
    connect(ui->rectButton, &QPushButton::clicked, this, &GraphicEditor::setRectMode);
    connect(ui->ellipseButton, &QPushButton::clicked, this, &GraphicEditor::setEllipseMode);
    connect(ui->lineButton, &QPushButton::clicked, this, &GraphicEditor::setLineMode);
    connect(ui->fillButton, &QPushButton::clicked, this, &GraphicEditor::setFillMode);
    connect(ui->saveButton, &QAction::triggered, this, &GraphicEditor::saveImage);
    connect(ui->loadButton, &QAction::triggered, this, &GraphicEditor::loadImage);
}

void GraphicEditor::slotTimer() {
    timer->stop();
    QRect view_rect = ui->graphicsView->viewport()->rect();
    scene->setSceneRect(0, 0, view_rect.width(), view_rect.height());
}

void GraphicEditor::brushSizeCanged() {
    scene->changeBrushSize(ui->brushSize->value());
}

void GraphicEditor::resizeEvent(QResizeEvent *event) {
    timer->start(100);
    QWidget::resizeEvent(event);
}

void GraphicEditor::setWhiteColor() {
    scene->setColor(255, 255, 255);
    ui->frame->setStyleSheet("background-color: rgb(255, 255, 255)");
}

void GraphicEditor::setBlackColor() {
    scene->setColor(0, 0, 0);
    ui->frame->setStyleSheet("background-color: rgb(0, 0, 0)");
}

void GraphicEditor::setRedColor() {
    scene->setColor(255, 0, 0);
    ui->frame->setStyleSheet("background-color: rgb(255, 0, 0)");
}

void GraphicEditor::setGreenColor() {
    scene->setColor(0, 128, 0);
    ui->frame->setStyleSheet("background-color: rgb(0, 128, 0)");
}

void GraphicEditor::setBlueColor() {
    scene->setColor(0, 0, 255);
    ui->frame->setStyleSheet("background-color: rgb(0, 0, 255)");
}

void GraphicEditor::setBrownColor() {
    scene->setColor(153, 51, 0);
    ui->frame->setStyleSheet("background-color: rgb(153, 51, 0)");
}

void GraphicEditor::setOrangeColor() {
    scene->setColor(255, 165, 0);
    ui->frame->setStyleSheet("background-color: rgb(255, 165, 0)");
}

void GraphicEditor::setPurpleColor() {
    scene->setColor(128, 0, 128);
    ui->frame->setStyleSheet("background-color: rgb(128, 0, 128)");
}

void GraphicEditor::setYellowColor() {
    scene->setColor(255, 255, 0);
    ui->frame->setStyleSheet("background-color: rgb(255, 255, 0)");
}

void GraphicEditor::setBrushMode() {
    scene->setDrawMode("BRUSH");
    ui->modeLabel->setText("Кисть");
}

void GraphicEditor::setRectMode() {
    scene->setDrawMode("RECT");
    ui->modeLabel->setText("Прямоугольник");
}

void GraphicEditor::setEllipseMode() {
    scene->setDrawMode("ELLIPSE");
    ui->modeLabel->setText("Эллипс");
}

void GraphicEditor::setLineMode() {
    scene->setDrawMode("LINE");
    ui->modeLabel->setText("Линия");
}

void GraphicEditor::setFillMode() {
    scene->setDrawMode("FILL");
    ui->modeLabel->setText("Заливка");
}

void GraphicEditor::saveImage() {
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"), "/untitled.png", tr("Images (*.png *.jpg)"));
    QPixmap pixMap = ui->graphicsView->grab();
    pixMap.save(path);
}

void GraphicEditor::loadImage() {
    scene->clear();
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.jpg)"));

    QPixmap picture(path);
    QGraphicsPixmapItem *pixmap_item = scene->addPixmap(picture);
    pixmap_item->setPos(0, 0);
    scene->setSceneRect(picture.rect());
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
