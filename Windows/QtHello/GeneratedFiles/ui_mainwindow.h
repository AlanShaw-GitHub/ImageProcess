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
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *RGB_R;
    QPushButton *RGB_G;
    QPushButton *RGB_B;
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
    QWidget *Advanced;
    QDialogButtonBox *buttonBox;
    QSlider *MixSlider;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QPushButton *pic_mix;
    QWidget *History;
    QTextEdit *history;
    QFrame *line;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(776, 764);
        MainWindow->setMaximumSize(QSize(776, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PictureArea = new QLabel(centralWidget);
        PictureArea->setObjectName(QStringLiteral("PictureArea"));
        PictureArea->setGeometry(QRect(0, 170, 781, 541));
        PictureArea->setStyleSheet(QLatin1String("QLabel {background-color : rgb(70, 71, 71); color : rgb(252, 255, 255); font: 57 25pt \"Apple Braille\";}\n"
"\n"
""));
        PictureArea->setAlignment(Qt::AlignCenter);
        PictureHistogram = new QLabel(centralWidget);
        PictureHistogram->setObjectName(QStringLiteral("PictureHistogram"));
        PictureHistogram->setGeometry(QRect(0, 0, 261, 171));
        PictureHistogram->setStyleSheet(QLatin1String("QLabel {background-color : rgb(70, 71, 71); color : rgb(252, 255, 255); font: 57 15pt \"Apple Braille\";}\n"
"\n"
""));
        PictureHistogram->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(260, 0, 511, 171));
        Basic = new QWidget();
        Basic->setObjectName(QStringLiteral("Basic"));
        resize_button = new QPushButton(Basic);
        resize_button->setObjectName(QStringLiteral("resize_button"));
        resize_button->setGeometry(QRect(14, 3, 151, 31));
        QFont font;
        font.setFamily(QStringLiteral("Apple LiGothic"));
        resize_button->setFont(font);
        resize_button->setIconSize(QSize(15, 16));
        groupBox = new QGroupBox(Basic);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 100, 181, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Apple LiGothic"));
        font1.setPointSize(13);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 161, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        RGB_R = new QPushButton(layoutWidget);
        RGB_R->setObjectName(QStringLiteral("RGB_R"));

        horizontalLayout->addWidget(RGB_R);

        RGB_G = new QPushButton(layoutWidget);
        RGB_G->setObjectName(QStringLiteral("RGB_G"));

        horizontalLayout->addWidget(RGB_G);

        RGB_B = new QPushButton(layoutWidget);
        RGB_B->setObjectName(QStringLiteral("RGB_B"));

        horizontalLayout->addWidget(RGB_B);

        sobel_picture = new QPushButton(Basic);
        sobel_picture->setObjectName(QStringLiteral("sobel_picture"));
        sobel_picture->setGeometry(QRect(188, 80, 131, 21));
        groupBox_2 = new QGroupBox(Basic);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 0, 131, 41));
        groupBox_2->setFont(font);
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
        groupBox_3->setAlignment(Qt::AlignCenter);
        ContrastSlider = new QSlider(groupBox_3);
        ContrastSlider->setObjectName(QStringLiteral("ContrastSlider"));
        ContrastSlider->setGeometry(QRect(2, 20, 121, 21));
        ContrastSlider->setMinimum(-50);
        ContrastSlider->setMaximum(50);
        ContrastSlider->setOrientation(Qt::Horizontal);
        blur_picture = new QPushButton(Basic);
        blur_picture->setObjectName(QStringLiteral("blur_picture"));
        blur_picture->setGeometry(QRect(188, 100, 131, 21));
        floodfill = new QPushButton(Basic);
        floodfill->setObjectName(QStringLiteral("floodfill"));
        floodfill->setGeometry(QRect(188, 120, 131, 21));
        rotate_picture = new QPushButton(Basic);
        rotate_picture->setObjectName(QStringLiteral("rotate_picture"));
        rotate_picture->setGeometry(QRect(358, 80, 131, 21));
        gray_picture = new QPushButton(Basic);
        gray_picture->setObjectName(QStringLiteral("gray_picture"));
        gray_picture->setGeometry(QRect(358, 100, 131, 21));
        cut_pic = new QPushButton(Basic);
        cut_pic->setObjectName(QStringLiteral("cut_pic"));
        cut_pic->setGeometry(QRect(358, 120, 131, 21));
        pic_size = new QTextBrowser(Basic);
        pic_size->setObjectName(QStringLiteral("pic_size"));
        pic_size->setGeometry(QRect(80, 70, 81, 24));
        pic_size->setFont(font);
        pic_size->setReadOnly(true);
        resize_coefficient = new QSlider(Basic);
        resize_coefficient->setObjectName(QStringLiteral("resize_coefficient"));
        resize_coefficient->setGeometry(QRect(60, 40, 101, 22));
        resize_coefficient->setValue(20);
        resize_coefficient->setOrientation(Qt::Horizontal);
        label = new QLabel(Basic);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 30, 21));
        QFont font2;
        font2.setPointSize(15);
        label->setFont(font2);
        buttonBox_2 = new QDialogButtonBox(Basic);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(170, 40, 164, 32));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_4 = new QLabel(Basic);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 70, 61, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Apple LiGothic"));
        font3.setPointSize(14);
        label_4->setFont(font3);
        label_4->setWordWrap(false);
        contrast_button = new QDialogButtonBox(Basic);
        contrast_button->setObjectName(QStringLiteral("contrast_button"));
        contrast_button->setGeometry(QRect(340, 40, 164, 32));
        contrast_button->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget->addTab(Basic, QString());
        Advanced = new QWidget();
        Advanced->setObjectName(QStringLiteral("Advanced"));
        buttonBox = new QDialogButtonBox(Advanced);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 100, 164, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        MixSlider = new QSlider(Advanced);
        MixSlider->setObjectName(QStringLiteral("MixSlider"));
        MixSlider->setGeometry(QRect(120, 70, 84, 22));
        MixSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Advanced);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(49, 70, 66, 19));
        layoutWidget1 = new QWidget(Advanced);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(310, 30, 107, 66));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        layoutWidget2 = new QWidget(Advanced);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 20, 163, 40));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font4;
        font4.setPointSize(13);
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        pic_mix = new QPushButton(layoutWidget2);
        pic_mix->setObjectName(QStringLiteral("pic_mix"));

        horizontalLayout_2->addWidget(pic_mix);

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
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
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
        PictureArea->setText(QApplication::translate("MainWindow", "Please first select a picture", Q_NULLPTR));
        PictureHistogram->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Please first select a picture</span></p></body></html>", Q_NULLPTR));
        resize_button->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\216\213\347\274\251", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\261\202\351\200\232\351\201\223\346\217\220\345\217\226\357\274\232", Q_NULLPTR));
        RGB_R->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        RGB_G->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        RGB_B->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
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
        tabWidget->setTabText(tabWidget->indexOf(Basic), QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\212\237\350\203\275", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\346\267\267\345\220\210\347\216\207(1/2)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\346\243\200\346\265\213", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\351\261\274\347\234\274\345\233\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\267\267\345\220\210", Q_NULLPTR));
        pic_mix->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\2072", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Advanced), QApplication::translate("MainWindow", "\351\253\230\347\272\247\345\212\237\350\203\275", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(History), QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\216\206\345\217\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
