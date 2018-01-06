#include <capturescreen.h>
#include <QApplication>
#include <mainwindow.h>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QDebug>
#include <basic_img.h>

CaptureScreen::CaptureScreen(QWidget *parent, bool is_part)
    : QWidget(parent)
    , m_isMousePress(false)
    , if_parts(is_part)
{
    initWindow();
    //setGeometry(0, 210, 800, 530);

    loadBackgroundPixmap();
}

CaptureScreen::~CaptureScreen()
{

}

void CaptureScreen::initWindow()
{
    this->setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //QLabel lable(this);
    //lable.setGeometry(0, 200, 781, 541);
    //setWindowState(Qt::WindowActive | Qt::WindowMaximized);
}

void CaptureScreen::loadBackgroundPixmap()
{
    QString pic_path = DEFAULTPATH + QString::number(MainWindow::getversion(), 10) + ".jpg";
    QPixmap *pixmap = new QPixmap(pic_path);
    *pixmap = pixmap->scaled(781, 541, Qt::KeepAspectRatio);
    m_loadPixmap = *pixmap;
    m_screenwidth = m_loadPixmap.width();
    m_screenheight = m_loadPixmap.height();
    if (m_screenwidth == 781)
    {
        //setGeometry(0, 212 + (541 - m_screenheight) / 2, 781, m_screenwidth);
		setGeometry(0, 170 + (541 - m_screenheight) / 2, 781, m_screenwidth);
    }
    else if (m_screenheight == 541)
    {
        setGeometry((781 - m_screenwidth) / 2, 170, m_screenwidth, 530);
    }
}

void CaptureScreen::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isMousePress = true;
        m_beginPoint = event->pos();
    }
    if (if_parts == 0)    // 漫水覆盖，只选择一个点
    {
        signalCompleteCature2(m_beginPoint);
        setVisible(0);
    }

    return QWidget::mousePressEvent(event);
}

void CaptureScreen::mouseMoveEvent(QMouseEvent* event)
{
    if (m_isMousePress)
    {
        m_endPoint = event->pos();
        update();
    }
    return QWidget::mouseMoveEvent(event);
}

void CaptureScreen::mouseReleaseEvent(QMouseEvent *event)
{
    m_endPoint = event->pos();
    m_isMousePress = false;
    signalCompleteCature(m_beginPoint, m_endPoint);
    setVisible(0);
    return QWidget::mouseReleaseEvent(event);
}

void CaptureScreen::paintEvent(QPaintEvent *event)
{
    m_painter.begin(this);          //进行重绘;

    QColor shadowColor = QColor(0, 0, 0, 100);                      //阴影颜色设置;
    m_painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap));    //设置画笔;
    m_painter.drawPixmap(0, 0, m_loadPixmap);                       //将背景图片画到窗体上;
    m_painter.fillRect(m_loadPixmap.rect(), shadowColor);           //画影罩效果;

    if (m_isMousePress)
    {
        QRect selectedRect = getRect(m_beginPoint, m_endPoint);
        m_capturePixmap = m_loadPixmap.copy(selectedRect);
        m_painter.drawPixmap(selectedRect.topLeft(), m_capturePixmap);
        m_painter.drawRect(selectedRect);
    }


    m_painter.end();  //重绘结束;
}

QRect CaptureScreen::getRect(const QPoint &beginPoint, const QPoint &endPoint)
{
    int x, y, width, height;
    width = qAbs(beginPoint.x() - endPoint.x());
    height = qAbs(beginPoint.y() - endPoint.y());
    x = beginPoint.x() < endPoint.x() ? beginPoint.x() : endPoint.x();
    y = beginPoint.y() < endPoint.y() ? beginPoint.y() : endPoint.y();

    QRect selectedRect = QRect(x, y, width, height);
    // 避免宽或高为零时拷贝截图有误;
    // 可以看QQ截图，当选取截图宽或高为零时默认为2;
    if (selectedRect.width() == 0)
    {
        selectedRect.setWidth(1);
    }
    if (selectedRect.height() == 0)
    {
        selectedRect.setHeight(1);
    }

    return selectedRect;
}

