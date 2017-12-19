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
    openAction->setStatusTip(tr("Open an existing file"));
    //connect(openAction, SIGNAL(QAction::triggered()), this, SLOT(MainWindow::open()));
    //connect(this, SIGNAL(MainWindow::open()), openAction, SLOT(&QAction::triggered));
    connect(openAction, &QAction::triggered, this, &MainWindow::open_picture);
    //QString file_name = emit MainWindow::open();
    QMenu *open = menuBar()->addMenu(tr("&File"));
    open->addAction(openAction);
    QToolBar *toolBar_open = addToolBar(tr("&File"));
    toolBar_open->addAction(openAction);

    saveAction = new QAction(QIcon("img/save.png"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Open an existing file"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::save_picture);
    QMenu *save = menuBar()->addMenu((tr("&Save")));
    open->addAction(saveAction);
    QToolBar *toolBar_save = addToolBar(tr("&Save"));
    toolBar_save->addAction(saveAction);




}

MainWindow::~MainWindow()
{
    delete ui;
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
        "",
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
    QString rm_command = "rm temp/*.jpg";
    char *command;
    QByteArray command2 = rm_command.toLatin1();
    command = command2.data();
    qDebug() << command;
    system(command);
    QString name = QFileDialog::getOpenFileName(NULL, "Open a file", "/Users/zuhxs/Documents", tr("Images (*.png *.jpg)"));
    if (name == NULL)
        return;
    if_selected = 1;
    this->pic_path = name;

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
    version += 1;
    MainWindow::load_picture(version);
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
void MainWindow::on_horizontalSlider_valueChanged(int value)
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


