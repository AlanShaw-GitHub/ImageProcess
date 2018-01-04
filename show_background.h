#ifndef SHOW_BACKGROUND_H
#define SHOW_BACKGROUND_H

#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QApplication>

class showImage:public QWidget
{
public:
    showImage(QWidget *parent = 0);
    ~showImage();
    QImage show1;
    void paintEvent(QPaintEvent *e);
};

#endif // SHOW_BACKGROUND_H
