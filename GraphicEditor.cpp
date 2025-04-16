#include "GraphicEditor.h"
#include "./ui_GraphicEditor.h"

GraphicEditor::GraphicEditor(QWidget *parent) : QMainWindow(parent), ui(new Ui::GraphicEditor) {
    ui->setupUi(this);

    scene = new PaintScene();
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &GraphicEditor::slotTimer);
    timer->start(100);

    //QPixmap pixmap("./resources/brush_image.png");
    //QIcon ButtonIcon(pixmap);
    //ui->brushButton->setIcon(ButtonIcon);
    //ui->brushButton->setIconSize(QSize(65, 65));

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

void GraphicEditor::setWhiteColor() {
    scene->setColor(255, 255, 255);
    ui->frame->setStyleSheet("background-color: rgb(255, 255, 255)");
    //brush_color[0] = 255;
    //brush_color[1] = 255;
    //brush_color[2] = 255;
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
}

void GraphicEditor::setRectMode() {
    scene->setDrawMode("RECT");
}

void GraphicEditor::setEllipseMode() {
    scene->setDrawMode("ELLIPSE");
}

void GraphicEditor::setLineMode() {
    scene->setDrawMode("LINE");
}

void GraphicEditor::setFillMode() {
    scene->setDrawMode("FILL");
}
