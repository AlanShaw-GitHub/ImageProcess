/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *PictureArea;
    QLabel *PictureHistogram;
    QTabWidget *tabWidget;
    QWidget *Basic;
    QPushButton *resize_button;
    QPushButton *sobel_picture;
    QGroupBox *groupBox_2;
    QSlider *horizontalSlider;
    QGroupBox *groupBox_3;
    QSlider *ContrastSlider;
    QPushButton *blur_picture;
    QPushButton *floodfill;
    QPushButton *rotate_picture;
    QPushButton *gray_picture;
    QPushButton *cut_pic;
    QTextBrowser *pic_size;
    QSlider *resize_coefficient;
    QLabel *label;
    QDialogButtonBox *buttonBox_2;
    QLabel *label_4;
    QDialogButtonBox *contrast_button;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *RGB_R;
    QPushButton *RGB_G;
    QPushButton *RGB_B;
    QLabel *label_5;
    QWidget *Advanced;
    QDialogButtonBox *buttonBox;
    QSlider *MixSlider;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QPushButton *pic_mix;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *thr_binary;
    QPushButton *thr_inv_bin;
    QPushButton *thr_trunc;
    QPushButton *thr_to_zero;
    QPushButton *thr_to_zero_inv;
    QPushButton *cam_camshift;
    QPushButton *cam_optiflow;
    QPushButton *cam_facedetect;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSlider *ThresholdSlider;
    QLabel *label_7;
    QWidget *History;
    QTextEdit *history;
    QFrame *line;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(776, 764);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(776, 764));
        MainWindow->setMaximumSize(QSize(776, 9999));
        MainWindow->setStyleSheet(QLatin1String("\n"
"QPushButton#resize_button {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(85, 170, 255);\n"
"	border-radius: 8px;\n"
"\n"
"}\n"
"\n"
"QPushButton#resize_button::hover {\n"
"	border-color: rgb(255, 170, 255);\n"
"	background-color: rgb(218, 218, 218);\n"
"}\n"
"\n"
"QPushButton {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(85, 170, 255);\n"
"	border-radius: 5px;\n"
"\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-color: rgb(255, 170, 255);\n"
"	background-color: rgb(218, 218, 218);\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-color: rgb(255, 170, 255);\n"
"	background-color: rgb(220, 220, 220);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PictureArea = new QLabel(centralWidget);
        PictureArea->setObjectName(QStringLiteral("PictureArea"));
        PictureArea->setGeometry(QRect(0, 170, 781, 541));
        PictureArea->setStyleSheet(QLatin1String("QLabel {background-color : rgb(70, 71, 71); color : rgb(252, 255, 255); font: 57 25pt \"Consolas\";}\n"
"\n"
""));
        PictureArea->setAlignment(Qt::AlignCenter);
        PictureHistogram = new QLabel(centralWidget);
        PictureHistogram->setObjectName(QStringLiteral("PictureHistogram"));
        PictureHistogram->setGeometry(QRect(0, 0, 261, 171));
        PictureHistogram->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"background-color : rgb(70, 71, 71); \n"
"color : rgb(252, 255, 255); \n"
"font: 57 15pt \"Consolas\";\n"
"}\n"
"\n"
""));
        PictureHistogram->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(260, 0, 511, 171));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(245, 245, 245);\n"
"\n"
""));
        Basic = new QWidget();
        Basic->setObjectName(QStringLiteral("Basic"));
        resize_button = new QPushButton(Basic);
        resize_button->setObjectName(QStringLiteral("resize_button"));
        resize_button->setGeometry(QRect(14, 3, 161, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resize_button->sizePolicy().hasHeightForWidth());
        resize_button->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        resize_button->setFont(font);
        resize_button->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        resize_button->setIconSize(QSize(15, 16));
        sobel_picture = new QPushButton(Basic);
        sobel_picture->setObjectName(QStringLiteral("sobel_picture"));
        sobel_picture->setGeometry(QRect(190, 80, 131, 18));
        sizePolicy1.setHeightForWidth(sobel_picture->sizePolicy().hasHeightForWidth());
        sobel_picture->setSizePolicy(sizePolicy1);
        sobel_picture->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        groupBox_2 = new QGroupBox(Basic);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 0, 131, 41));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(2, 20, 121, 21));
        horizontalSlider->setMinimum(-100);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(Basic);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 0, 131, 41));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        ContrastSlider = new QSlider(groupBox_3);
        ContrastSlider->setObjectName(QStringLiteral("ContrastSlider"));
        ContrastSlider->setGeometry(QRect(2, 20, 121, 21));
        ContrastSlider->setMinimum(-50);
        ContrastSlider->setMaximum(50);
        ContrastSlider->setOrientation(Qt::Horizontal);
        blur_picture = new QPushButton(Basic);
        blur_picture->setObjectName(QStringLiteral("blur_picture"));
        blur_picture->setGeometry(QRect(190, 103, 131, 18));
        sizePolicy1.setHeightForWidth(blur_picture->sizePolicy().hasHeightForWidth());
        blur_picture->setSizePolicy(sizePolicy1);
        blur_picture->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        floodfill = new QPushButton(Basic);
        floodfill->setObjectName(QStringLiteral("floodfill"));
        floodfill->setGeometry(QRect(190, 125, 131, 18));
        floodfill->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        rotate_picture = new QPushButton(Basic);
        rotate_picture->setObjectName(QStringLiteral("rotate_picture"));
        rotate_picture->setGeometry(QRect(358, 80, 131, 18));
        sizePolicy1.setHeightForWidth(rotate_picture->sizePolicy().hasHeightForWidth());
        rotate_picture->setSizePolicy(sizePolicy1);
        rotate_picture->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gray_picture = new QPushButton(Basic);
        gray_picture->setObjectName(QStringLiteral("gray_picture"));
        gray_picture->setGeometry(QRect(358, 103, 131, 18));
        sizePolicy1.setHeightForWidth(gray_picture->sizePolicy().hasHeightForWidth());
        gray_picture->setSizePolicy(sizePolicy1);
        gray_picture->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        cut_pic = new QPushButton(Basic);
        cut_pic->setObjectName(QStringLiteral("cut_pic"));
        cut_pic->setGeometry(QRect(358, 125, 131, 18));
        sizePolicy1.setHeightForWidth(cut_pic->sizePolicy().hasHeightForWidth());
        cut_pic->setSizePolicy(sizePolicy1);
        cut_pic->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pic_size = new QTextBrowser(Basic);
        pic_size->setObjectName(QStringLiteral("pic_size"));
        pic_size->setGeometry(QRect(80, 70, 81, 24));
        QFont font1;
        font1.setFamily(QStringLiteral("Apple LiGothic"));
        pic_size->setFont(font1);
        pic_size->setReadOnly(true);
        resize_coefficient = new QSlider(Basic);
        resize_coefficient->setObjectName(QStringLiteral("resize_coefficient"));
        resize_coefficient->setGeometry(QRect(60, 40, 101, 22));
        resize_coefficient->setValue(20);
        resize_coefficient->setOrientation(Qt::Horizontal);
        label = new QLabel(Basic);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 30, 21));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        buttonBox_2 = new QDialogButtonBox(Basic);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(185, 45, 141, 32));
        sizePolicy1.setHeightForWidth(buttonBox_2->sizePolicy().hasHeightForWidth());
        buttonBox_2->setSizePolicy(sizePolicy1);
        buttonBox_2->setStyleSheet(QLatin1String("min-width: 65;\n"
"min-height: 20;"));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_4 = new QLabel(Basic);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(12, 72, 61, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(7);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("font: 7pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4->setWordWrap(false);
        contrast_button = new QDialogButtonBox(Basic);
        contrast_button->setObjectName(QStringLiteral("contrast_button"));
        contrast_button->setGeometry(QRect(352, 45, 141, 32));
        sizePolicy1.setHeightForWidth(contrast_button->sizePolicy().hasHeightForWidth());
        contrast_button->setSizePolicy(sizePolicy1);
        contrast_button->setStyleSheet(QLatin1String("min-width: 65;\n"
"min-height: 20;"));
        contrast_button->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Basic);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 120, 161, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RGB_R = new QPushButton(layoutWidget);
        RGB_R->setObjectName(QStringLiteral("RGB_R"));
        sizePolicy1.setHeightForWidth(RGB_R->sizePolicy().hasHeightForWidth());
        RGB_R->setSizePolicy(sizePolicy1);
        RGB_R->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(RGB_R);

        RGB_G = new QPushButton(layoutWidget);
        RGB_G->setObjectName(QStringLiteral("RGB_G"));
        sizePolicy1.setHeightForWidth(RGB_G->sizePolicy().hasHeightForWidth());
        RGB_G->setSizePolicy(sizePolicy1);
        RGB_G->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(RGB_G);

        RGB_B = new QPushButton(layoutWidget);
        RGB_B->setObjectName(QStringLiteral("RGB_B"));
        sizePolicy1.setHeightForWidth(RGB_B->sizePolicy().hasHeightForWidth());
        RGB_B->setSizePolicy(sizePolicy1);
        RGB_B->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(RGB_B);

        label_5 = new QLabel(Basic);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 105, 54, 12));
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tabWidget->addTab(Basic, QString());
        Advanced = new QWidget();
        Advanced->setObjectName(QStringLiteral("Advanced"));
        Advanced->setStyleSheet(QStringLiteral(""));
        buttonBox = new QDialogButtonBox(Advanced);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 70, 151, 32));
        buttonBox->setStyleSheet(QString::fromUtf8("min-width: 70;\n"
"min-height: 20;\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        MixSlider = new QSlider(Advanced);
        MixSlider->setObjectName(QStringLiteral("MixSlider"));
        MixSlider->setGeometry(QRect(120, 50, 84, 22));
        MixSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Advanced);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(49, 50, 66, 19));
        label_2->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        layoutWidget1 = new QWidget(Advanced);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 0, 163, 40));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        pic_mix = new QPushButton(layoutWidget1);
        pic_mix->setObjectName(QStringLiteral("pic_mix"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pic_mix->sizePolicy().hasHeightForWidth());
        pic_mix->setSizePolicy(sizePolicy2);
        pic_mix->setStyleSheet(QString::fromUtf8("min-height: 20px;\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(pic_mix);

        horizontalLayoutWidget = new QWidget(Advanced);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 110, 160, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("min-width: 65;\n"
"min-height: 25;\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("min-width: 65;\n"
"min-height: 25;\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(pushButton);

        thr_binary = new QPushButton(Advanced);
        thr_binary->setObjectName(QStringLiteral("thr_binary"));
        thr_binary->setGeometry(QRect(240, 38, 75, 23));
        sizePolicy1.setHeightForWidth(thr_binary->sizePolicy().hasHeightForWidth());
        thr_binary->setSizePolicy(sizePolicy1);
        thr_binary->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        thr_inv_bin = new QPushButton(Advanced);
        thr_inv_bin->setObjectName(QStringLiteral("thr_inv_bin"));
        thr_inv_bin->setGeometry(QRect(240, 68, 121, 23));
        sizePolicy1.setHeightForWidth(thr_inv_bin->sizePolicy().hasHeightForWidth());
        thr_inv_bin->setSizePolicy(sizePolicy1);
        thr_inv_bin->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        thr_trunc = new QPushButton(Advanced);
        thr_trunc->setObjectName(QStringLiteral("thr_trunc"));
        thr_trunc->setGeometry(QRect(400, 38, 75, 23));
        sizePolicy1.setHeightForWidth(thr_trunc->sizePolicy().hasHeightForWidth());
        thr_trunc->setSizePolicy(sizePolicy1);
        thr_trunc->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        thr_to_zero = new QPushButton(Advanced);
        thr_to_zero->setObjectName(QStringLiteral("thr_to_zero"));
        thr_to_zero->setGeometry(QRect(320, 38, 75, 23));
        sizePolicy1.setHeightForWidth(thr_to_zero->sizePolicy().hasHeightForWidth());
        thr_to_zero->setSizePolicy(sizePolicy1);
        thr_to_zero->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        thr_to_zero_inv = new QPushButton(Advanced);
        thr_to_zero_inv->setObjectName(QStringLiteral("thr_to_zero_inv"));
        thr_to_zero_inv->setGeometry(QRect(363, 68, 111, 23));
        sizePolicy1.setHeightForWidth(thr_to_zero_inv->sizePolicy().hasHeightForWidth());
        thr_to_zero_inv->setSizePolicy(sizePolicy1);
        thr_to_zero_inv->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        cam_camshift = new QPushButton(Advanced);
        cam_camshift->setObjectName(QStringLiteral("cam_camshift"));
        cam_camshift->setGeometry(QRect(240, 120, 75, 23));
        sizePolicy1.setHeightForWidth(cam_camshift->sizePolicy().hasHeightForWidth());
        cam_camshift->setSizePolicy(sizePolicy1);
        cam_camshift->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        cam_optiflow = new QPushButton(Advanced);
        cam_optiflow->setObjectName(QStringLiteral("cam_optiflow"));
        cam_optiflow->setGeometry(QRect(320, 120, 75, 23));
        sizePolicy1.setHeightForWidth(cam_optiflow->sizePolicy().hasHeightForWidth());
        cam_optiflow->setSizePolicy(sizePolicy1);
        cam_optiflow->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        cam_facedetect = new QPushButton(Advanced);
        cam_facedetect->setObjectName(QStringLiteral("cam_facedetect"));
        cam_facedetect->setGeometry(QRect(400, 120, 75, 23));
        sizePolicy1.setHeightForWidth(cam_facedetect->sizePolicy().hasHeightForWidth());
        cam_facedetect->setSizePolicy(sizePolicy1);
        cam_facedetect->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        horizontalLayoutWidget_2 = new QWidget(Advanced);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(280, 0, 160, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_4->addWidget(label_6);

        ThresholdSlider = new QSlider(horizontalLayoutWidget_2);
        ThresholdSlider->setObjectName(QStringLiteral("ThresholdSlider"));
        ThresholdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(ThresholdSlider);

        label_7 = new QLabel(Advanced);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(328, 98, 61, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tabWidget->addTab(Advanced, QString());
        History = new QWidget();
        History->setObjectName(QStringLiteral("History"));
        history = new QTextEdit(History);
        history->setObjectName(QStringLiteral("history"));
        history->setGeometry(QRect(10, 10, 491, 121));
        history->setReadOnly(true);
        tabWidget->addTab(History, QString());
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-20, 160, 811, 20));
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 776, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        PictureArea->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Please select a picture first</span></p></body></html>", Q_NULLPTR));
        PictureHistogram->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Please select a picture first</span></p></body></html>", Q_NULLPTR));
        resize_button->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\216\213\347\274\251", Q_NULLPTR));
        sobel_picture->setText(QApplication::translate("MainWindow", " \345\233\276\345\203\217\351\224\220\345\214\226", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\344\272\256\345\272\246\350\260\203\346\225\264", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\257\271\346\257\224\345\272\246\350\260\203\346\225\264", Q_NULLPTR));
        blur_picture->setText(QApplication::translate("MainWindow", " \345\233\276\345\203\217\346\250\241\347\263\212", Q_NULLPTR));
        floodfill->setText(QApplication::translate("MainWindow", "\346\274\253\346\260\264\345\241\253\345\205\205", Q_NULLPTR));
        rotate_picture->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\346\227\213\350\275\254", Q_NULLPTR));
        gray_picture->setText(QApplication::translate("MainWindow", "\350\275\254\344\270\272\347\201\260\345\272\246\345\233\276", Q_NULLPTR));
        cut_pic->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\350\243\201\345\211\252", Q_NULLPTR));
        pic_size->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Apple LiGothic'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:13pt;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt;\">\345\200\215\347\216\207</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\345\275\223\345\211\215\345\244\247\345\260\217</span></p></body></html>", Q_NULLPTR));
        RGB_R->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        RGB_G->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        RGB_B->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\233\276\345\261\202\351\200\232\351\201\223", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Basic), QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\212\237\350\203\275", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\267\267\345\220\210\347\216\207(1/2)", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\345\233\276\347\211\207\346\267\267\345\220\210</span></p></body></html>", Q_NULLPTR));
        pic_mix->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\2072", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\351\261\274\347\234\274\345\233\276", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\346\243\200\346\265\213", Q_NULLPTR));
        thr_binary->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274", Q_NULLPTR));
        thr_inv_bin->setText(QApplication::translate("MainWindow", "\345\217\215\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274", Q_NULLPTR));
        thr_trunc->setText(QApplication::translate("MainWindow", "\346\210\252\346\226\255\351\230\210\345\200\274", Q_NULLPTR));
        thr_to_zero->setText(QApplication::translate("MainWindow", "\351\230\210\345\200\274\345\214\226\344\270\2720", Q_NULLPTR));
        thr_to_zero_inv->setText(QApplication::translate("MainWindow", "\345\217\215\351\230\210\345\200\274\345\214\226\344\270\2720", Q_NULLPTR));
        cam_camshift->setText(QApplication::translate("MainWindow", "\347\211\251\344\275\223\350\277\275\350\270\252", Q_NULLPTR));
        cam_optiflow->setText(QApplication::translate("MainWindow", "\345\205\211\346\265\201\347\256\227\346\263\225", Q_NULLPTR));
        cam_facedetect->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\346\243\200\346\265\213", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\351\230\210\345\200\274\345\214\226", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264\345\212\237\350\203\275", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Advanced), QApplication::translate("MainWindow", "\351\253\230\347\272\247\345\212\237\350\203\275", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(History), QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\216\206\345\217\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
