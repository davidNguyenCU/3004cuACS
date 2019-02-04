#include "cuacsview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CUACSView w;
    w.show();

    return a.exec();
}
