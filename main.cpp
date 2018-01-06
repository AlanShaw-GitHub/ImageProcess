#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

void delay1(int seconds);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    //CaptureScreen select = new CaptureScreen;

	QPixmap pixmap("img/screen.jpg");
	QSplashScreen screen(pixmap);
	//screen.resize(640, 480);
	screen.show();

	delay1(2500);

    w.show();

	screen.finish(&w);

    return app.exec();
}

void delay1(int seconds)
{
	clock_t start = clock();
	clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC / 1000;
	while ((clock() - start) < lay)
		;
}
