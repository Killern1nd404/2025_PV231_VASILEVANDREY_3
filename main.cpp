#include "GraphicEditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicEditor w;
    w.show();
    return a.exec();
}
