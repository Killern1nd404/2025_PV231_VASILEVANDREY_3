#include "GraphicEditor.h"
#include "./ui_GraphicEditor.h"

GraphicEditor::GraphicEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphicEditor)
{
    ui->setupUi(this);
}

GraphicEditor::~GraphicEditor()
{
    delete ui;
}
