#include "cuacsview.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    CUACSView x;
    w.show();

    return a.exec();
}
