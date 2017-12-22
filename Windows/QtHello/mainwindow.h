#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "select_pic_first.h"
#include <fstream>
#include <iostream>

#define DEFAULTPATH "D:\\temp\\"      // a catalog to save the picture

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_resize_button_clicked();

    void on_RGB_R_clicked();

    void undo();

    void on_rotate_picture_clicked();

    void on_sobel_picture_clicked();

    void on_blur_picture_clicked();

    void on_gray_picture_clicked();

    void open_picture();

    void save_picture();

    void on_RGB_G_clicked();

    void on_RGB_B_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    int version; // used to mark the picture editing
    Ui::MainWindow *ui;
    QAction *openAction;
    QAction *saveAction;
    QAction *undoAction;
    QPushButton *resize_button;
    QString pic_path;
    void load_picture(int version);
    bool if_selected;
    void load_histogram(QString path);
    Select_pic_first *Pic_Select_Dialog;
    QString GetName();
    QString GetSize();
};



#endif // MAINWINDOW_H
