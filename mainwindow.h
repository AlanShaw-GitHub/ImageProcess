#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "select_pic_first.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <capturescreen.h>
#include <show_background.h>

#define DEFAULTPATH "temp/"      // a catalog to save the picture

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static int getversion();
    static int version;  // used to mark the picture editing
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

    void Mouse_click(bool is_part);

    void onCompleteCature(QPoint start_point, QPoint end_point);

    void on_cut_pic_clicked();

    void on_pic_mix_clicked();

    void on_MixSlider_valueChanged(int value);

    QString GetSize(QString mix_path);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_ContrastSlider_valueChanged(int value);

    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

    void on_contrast_button_accepted();

    void on_contrast_button_rejected();

    void on_floodfill_clicked();

    void onCompleteCature2(QPoint start_point);

    void on_thr_binary_clicked();

    void on_thr_bin_inv_clicked();

    void on_thr_trunc_clicked();

    void on_thr_tozero_clicked();

    void on_thr_toz_inv_clicked();

    void on_cam_camshift_clicked();

    void on_cam_optiflow_clicked();

    void on_cam_facedet_clicked();

private:
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
    QString history;
    int operate_count;
    CaptureScreen* captureHelper;
    int mix_pic_loaded;
    int already_have_mixed;
    int if_real_mix_change;
    int if_brightness_changed;
    int if_contrast_changed;
    int if_real_light_changed;
    int if_real_contrast_changed;
};



#endif // MAINWINDOW_H
