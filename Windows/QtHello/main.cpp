#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //CaptureScreen select = new CaptureScreen;

    w.show();

    return a.exec();
}
