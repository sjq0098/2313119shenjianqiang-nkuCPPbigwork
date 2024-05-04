#include "DrawingBoard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawingboardWidget w;
    w.show();
     return a.exec();
}
