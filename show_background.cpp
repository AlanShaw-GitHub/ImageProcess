#include "show_background.h"
#include <mainwindow.h>
showImage::showImage(QWidget *parent):QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowActive);
    QString back_path = QApplication::applicationDirPath() + "/img/background.jpg";
    show1.load(back_path);//文件路径
    this->show();
}
showImage::~showImage()
{
}
void showImage::paintEvent(QPaintEvent *e)
{
    QPainter pp(this);
    QRect Temp(0,0,this->width(),this->height());
    pp.drawImage(Temp,show1);
}
