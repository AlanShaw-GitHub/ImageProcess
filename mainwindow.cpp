#include "mainwindow.h"
#include "stdlib.h"
#include <stdio.h>
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QPushButton>
#include <string>
#include <iostream>
#include <stdio.h>
#include "include/IPP_World.h"
#include "select_pic_first.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath();
    version = 0;
    //ui->MainWindow->version = 0;
    ui->setupUi(this);
    setWindowTitle("Picture Editor");

    openAction = new QAction(QIcon("img/file.png"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing picture"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open_picture);
    QMenu *open = menuBar()->addMenu(tr("&File"));
    open->addAction(openAction);
    QToolBar *toolBar_open = addToolBar(tr("&File"));
    toolBar_open->addAction(openAction);

    saveAction = new QAction(QIcon("img/save.png"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the current picture"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::save_picture);
    QMenu *save = menuBar()->addMenu((tr("&Save")));
    open->addAction(saveAction);
    QToolBar *toolBar_save = addToolBar(tr("&Save"));
    toolBar_save->addAction(saveAction);

    undoAction = new QAction(QIcon("img/undo.png"), tr("&Undo..."), this);
    undoAction->setShortcuts(QKeySequence::Save);
    undoAction->setStatusTip(tr("Undo the last operation"));
    connect(undoAction, &QAction::triggered, this, &MainWindow::undo);
    QMenu *undo = menuBar()->addMenu((tr("&Command")));
    undo->addAction(undoAction);
    QToolBar *toolBar_undo = addToolBar(tr("&Undo"));
    toolBar_undo->addAction(undoAction);




}

int MainWindow::version = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::undo()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    if (version == 0)
    {
        QMessageBox message(QMessageBox::NoIcon, "error", "It is the origin picture!", QMessageBox::Ok, NULL);
        message.exec();
        //QMessageBox message(QMessageBox::NoIcon, "error", "This is the original picture!", QMessageBox::Yes, NULL);
        return;
    }
    version--;
    qDebug() << version;
    load_picture(version);
    history += QString(operate_count+0x30) + ". 撤销上次操作\n";
    operate_count++;
    ui->history->setText(history);
    return;

}

void MainWindow::save_picture()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    QString img = GetName();
    QString filename = QFileDialog::getSaveFileName(this,
        tr("Save Image"),
        "/Users/zuhxs/Desktop/shuluo",
        tr("*.jpg;; *.png;; *.bmp")); //选择路径
    if(filename.isEmpty())
    {
        return;
    }

    else
    {
        QString command = "cp " + img + " " + filename;
        char *ch;
        QByteArray ba = command.toLatin1();
        ch=ba.data();
        qDebug() << ch;
        system(ch);
        QMessageBox::about(this,
                    tr("Saved"),
                    tr("Already saved!"));
        history += "保存图片到 " + filename + "\n";
        ui->history->setText(history);
    }
}

void MainWindow::open_picture()
{
    if (if_selected)
    {
        QMessageBox message(QMessageBox::NoIcon, "warning", "After opening a new picture you will lose all previous records, continue?", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::No)
            return;
    }
    history.clear();
    operate_count = 1;
    QString rm_command = "rm temp/*.jpg";
    char *command;
    QByteArray command2 = rm_command.toLatin1();
    command = command2.data();
    qDebug() << command;
    system(command);
    QString name = QFileDialog::getOpenFileName(NULL, "Open a file", "/Users/zuhxs/Desktop/pic", tr("Images (*.png *.jpg)"));
    if (name == NULL)
        return;
    if_selected = 1;
    this->pic_path = name;
    history += QString(operate_count+0x30) + ". 打开 " + name + "\n";
    operate_count++;
    ui->history->setText(history);

    QString cp_command = "cp " + pic_path + " " + GetName();
    char*  ch;
    QByteArray ba = cp_command.toLatin1();
    ch=ba.data();
    qDebug() << ch;
    system(ch);
    load_picture(version);
}

void MainWindow::load_picture(int version)
{
    QString pic_path = DEFAULTPATH + QString::number(version, 10) + ".jpg";
    QImage *pixmap = new QImage(pic_path);
    *pixmap = pixmap->scaled(781, 541, Qt::KeepAspectRatio);
    ui->PictureArea->setPixmap(QPixmap::fromImage(*pixmap));
    ui->PictureArea->setAlignment(Qt::AlignCenter);
    IPP_hist(version);
    QString hist_path = "temp/hist.jpg";
    MainWindow::load_histogram(hist_path);
    ui->pic_size->setText(GetSize());
}

void MainWindow::load_histogram(QString path)
{
    QImage *pixmap = new QImage(path);
    *pixmap = pixmap->scaled(261, 171, Qt::KeepAspectRatio);
    ui->PictureHistogram->setPixmap(QPixmap::fromImage(*pixmap));
    ui->PictureHistogram->setScaledContents(1);
    ui->PictureHistogram->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_resize_button_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_resize(version, COMPRESS , ui->resize_coefficient->value());
    history += QString(operate_count+0x30) + ". 以 " + ui->resize_coefficient->value() + "的倍率压缩" + "\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}

void MainWindow::on_RGB_R_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_split(version, RED);
    history += QString(operate_count+0x30) + ". 获取图片的红色RGB通道\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}

void MainWindow::on_rotate_picture_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_rotate(version, 90);
    version += 1;
    MainWindow::load_picture(version);
}

void MainWindow::on_sobel_picture_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_sobel(version);
    history += QString(operate_count+0x30) + ". 图像锐化\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}

void MainWindow::on_blur_picture_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_blur(version, 10);
    history += QString(operate_count+0x30) + ". 图像模糊\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}

void MainWindow::on_gray_picture_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_gray(version);
    history += QString(operate_count+0x30) + ". 转为灰度图\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}

void MainWindow::on_RGB_G_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_split(version, GREEN);
    history += QString(operate_count+0x30) + ". 获取图片的绿色RGB通道\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}


void MainWindow::on_RGB_B_clicked()
{
    if (!if_selected){
        QMessageBox message(QMessageBox::NoIcon, "error", "Please select a picture first!", QMessageBox::Yes | QMessageBox::No, NULL);
        if (message.exec() == QMessageBox::Yes){
            MainWindow::open_picture();
        }
        return;
    }
    IPP_split(version, BLUE);
    history += QString(operate_count+0x30) + ". 获取图片的绿色RGB通道\n";
    operate_count++;
    ui->history->setText(history);
    version += 1;
    MainWindow::load_picture(version);
}

int MainWindow::getversion()
{
    return version;
}

QString MainWindow::GetName()
{
    QString pic_path = DEFAULTPATH + QString::number(version, 10) + ".jpg";
    return pic_path;
}

QString MainWindow::GetSize()
{
    QString filepath = GetName();
    QByteArray temp = filepath.toLatin1();
    const char *temp_path = temp.data();
    ifstream in(temp_path);
    in.seekg(0, ios::end); //设置文件指针到文件流的尾部
    streampos ps = in.tellg(); //读取文件指针的位置
    double size = (double)ps / 1024;
    QString result = QString::number(size, 10, 3) + "kb";
    return result;
}

void delay(int seconds)
{
   clock_t start = clock();
   clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC / 1000;
   while ((clock()-start) < lay)
     ;
}
void MainWindow::on_horizontalSlider_valueChanged(int value)    // 改变亮度
{
    static int last_light_value = 0;
    if (!if_selected){
        return;
    }
    delay(100);
    IPP_brightness(version, value - last_light_value);
    version += 1;
    MainWindow::load_picture(version);
    last_light_value = value;
}

void MainWindow::Mouse_click()
{
    captureHelper = new CaptureScreen(this);
    connect(captureHelper, SIGNAL(signalCompleteCature(QPoint, QPoint)), this, SLOT(onCompleteCature(QPoint, QPoint)));
    captureHelper->show();
}


void MainWindow::onCompleteCature(QPoint start_point, QPoint end_point)
{
    //version++;
    qDebug() << start_point << " " << end_point;
    int row, col;
    row = IPP_rows(version);  // 宽度
    col = IPP_cols(version);  // 长度
    int pic_show_cols, pic_show_rows;  // 当前界面展示的图片长度与图片宽度
    double x = col / row;
    double y = 781.0 / 541.0;
    if (x <= y)
    {
        pic_show_rows = 541;
        pic_show_cols = (double)col * 541.0 / (double)row;
    }
    else{
        pic_show_cols = 781;
        pic_show_rows = row * 781.0 / (double)col;
    }
    int real_x1, real_x2, real_y1, real_y2;
    qDebug() << col << " " << row;
    qDebug() << "the actual size: " << pic_show_cols << " " << pic_show_rows;
    if (start_point.x() == end_point.x() || start_point.y() == end_point.y())
    {
        QMessageBox message(QMessageBox::NoIcon, "error", "Error on selecting parts!", QMessageBox::Yes, NULL);
        message.exec();
        return;
    }
    int sim_x1, sim_x2, sim_y1, sim_y2;
    if (start_point.x() < end_point.x())
    {
        if (start_point.y() < end_point.y())
        {
            sim_x1 = start_point.x();
            sim_y1 = start_point.y();
            sim_x2 = end_point.x();
            sim_y2 = end_point.y();
        }
        else
        {
            sim_x1 = start_point.x();
            sim_y1 = end_point.y();
            sim_x2 = end_point.x();
            sim_y2 = start_point.y();
        }
    }
    else
    {
        if (start_point.y() < end_point.y())
        {
            sim_x1 = end_point.x();
            sim_x2 = start_point.x();
            sim_y1 = start_point.y();
            sim_y2 = end_point.y();
        }
        else
        {
            sim_x1 = end_point.x();
            sim_y1 = end_point.y();
            sim_x2 = start_point.x();
            sim_y2 = start_point.y();
        }
    }

    double temp = (double)sim_x1 / (double)pic_show_cols;
    real_x1 = temp * col;
    temp = (double)sim_x2 / (double)pic_show_cols;
    real_x2 = temp * col;
    temp = (double)sim_y1 / (double)pic_show_rows;
    real_y1 = temp * row;
    temp = (double)sim_y2 / (double)pic_show_rows;
    real_y2 = temp * row;
    qDebug() << "(" << real_x1 << ", " << real_y1 << "), (" << real_x2 << ", " << real_y2 << ")";

    IPP_cut(version, real_x1, real_y1, real_x2 - real_x1, real_y2 - real_y1);

    //QString path = GetName();
    //captureImage.save(path);
    //load_picture(version);
}

void MainWindow::on_cut_pic_clicked()
{
    Mouse_click();
}
