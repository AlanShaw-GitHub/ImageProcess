#ifndef CAPTURESCREEN_H
#define CAPTURESCREEN_H

#include <QWidget>
#include <QPainter>
#include "include/basic_img.h"

class CaptureScreen : public QWidget
{
    Q_OBJECT

public:
    CaptureScreen(QWidget *parent = 0, bool is_part = 1);
    ~CaptureScreen();

Q_SIGNALS:
    void signalCompleteCature(QPoint m_beginPoint, QPoint m_endPoint);
    void signalCompleteCature2(QPoint m_beginPoint);

private:
    void initWindow();
    void loadBackgroundPixmap();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    QRect getRect(const QPoint &beginPoint, const QPoint &endPoint);

private:
    bool if_parts; // 用于区分裁剪与漫水填充, 1代表选中区域，0代表选中一个点
    bool m_isMousePress;
    QPixmap m_loadPixmap, m_capturePixmap;
    int m_screenwidth;
    int m_screenheight;
    QPoint m_beginPoint, m_endPoint;
    QPainter m_painter;
};

#endif // CAPTURESCREEN_H
