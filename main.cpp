#include "mainwindow.h"
#include <QApplication>
#include <show_background.h>
#include <QDebug>
#include <QSplashScreen>

void delay1(int seconds)
{
   clock_t start = clock();
   clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC / 1000;
   while ((clock()-start) < lay)
     ;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString back_pic_path = QApplication::applicationDirPath() + "/img/c.jpg";
    QPixmap pixmap(back_pic_path);      //绑定一个图片
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(pixmap);
    splash->show();                            //显示启动画面
    //app.processEvents();                //加载其他的模块

    //mainWindow dialog;
    delay1(2500);
    MainWindow w;
    w.show();
    //dialog.show();

    splash->finish(&w);     //当主窗口启动后，启动画面隐藏
    delete splash;

    return a.exec();
}
