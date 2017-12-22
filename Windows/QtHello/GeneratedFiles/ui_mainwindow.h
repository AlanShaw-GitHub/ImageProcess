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
#include <QtWidgets/QToolBar>
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
    QPushButton *sobel_picture;
    QGroupBox *groupBox_2;
    QSlider *horizontalSlider;
    QGroupBox *groupBox_3;
    QSlider *horizontalSlider_3;
    QPushButton *blur_picture;
    QPushButton *pushButton_10;
    QPushButton *rotate_picture;
    QPushButton *gray_picture;
    QPushButton *pushButton_13;
    QTextBrowser *textBrowser_4;
    QTextBrowser *pic_size;
    QSlider *resize_coefficient;
    QTextBrowser *textBrowser_6;
    QPushButton *RGB_R;
    QPushButton *RGB_G;
    QPushButton *RGB_B;
    QWidget *Advanced;
    QPushButton *pushButton;
    QWidget *History;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(796, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PictureArea = new QLabel(centralWidget);
        PictureArea->setObjectName(QStringLiteral("PictureArea"));
        PictureArea->setGeometry(QRect(30, 200, 781, 491));
        PictureArea->setStyleSheet(QLatin1String("QLabel {background-color : rgb(70, 71, 71); color : rgb(252, 255, 255); font: 57 25pt \"Apple Braille\";}\n"
"\n"
""));
        PictureArea->setAlignment(Qt::AlignCenter);
        PictureHistogram = new QLabel(centralWidget);
        PictureHistogram->setObjectName(QStringLiteral("PictureHistogram"));
        PictureHistogram->setGeometry(QRect(20, 10, 261, 171));
        PictureHistogram->setStyleSheet(QLatin1String("QLabel {background-color : rgb(70, 71, 71); color : rgb(252, 255, 255); font: 57 15pt \"Apple Braille\";}\n"
"\n"
""));
        PictureHistogram->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(300, 0, 541, 191));
        Basic = new QWidget();
        Basic->setObjectName(QStringLiteral("Basic"));
        resize_button = new QPushButton(Basic);
        resize_button->setObjectName(QStringLiteral("resize_button"));
        resize_button->setGeometry(QRect(30, 10, 181, 31));
        QFont font;
        font.setFamily(QStringLiteral("Apple LiGothic"));
        resize_button->setFont(font);
        resize_button->setIconSize(QSize(15, 16));
        groupBox = new QGroupBox(Basic);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 110, 251, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Apple LiGothic"));
        font1.setPointSize(13);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 231, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sobel_picture = new QPushButton(Basic);
        sobel_picture->setObjectName(QStringLiteral("sobel_picture"));
        sobel_picture->setGeometry(QRect(270, 60, 131, 31));
        groupBox_2 = new QGroupBox(Basic);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(270, 10, 131, 41));
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
        groupBox_3->setGeometry(QRect(400, 10, 131, 41));
        groupBox_3->setFont(font);
        groupBox_3->setAlignment(Qt::AlignCenter);
        horizontalSlider_3 = new QSlider(groupBox_3);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(2, 20, 121, 21));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        blur_picture = new QPushButton(Basic);
        blur_picture->setObjectName(QStringLiteral("blur_picture"));
        blur_picture->setGeometry(QRect(270, 90, 131, 31));
        pushButton_10 = new QPushButton(Basic);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(270, 120, 131, 31));
        rotate_picture = new QPushButton(Basic);
        rotate_picture->setObjectName(QStringLiteral("rotate_picture"));
        rotate_picture->setGeometry(QRect(400, 60, 131, 31));
        gray_picture = new QPushButton(Basic);
        gray_picture->setObjectName(QStringLiteral("gray_picture"));
        gray_picture->setGeometry(QRect(400, 90, 131, 31));
        pushButton_13 = new QPushButton(Basic);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(400, 120, 131, 31));
        textBrowser_4 = new QTextBrowser(Basic);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(40, 80, 91, 24));
        textBrowser_4->setFont(font);
        pic_size = new QTextBrowser(Basic);
        pic_size->setObjectName(QStringLiteral("pic_size"));
        pic_size->setGeometry(QRect(130, 80, 81, 24));
        pic_size->setFont(font);
        pic_size->setReadOnly(true);
        resize_coefficient = new QSlider(Basic);
        resize_coefficient->setObjectName(QStringLiteral("resize_coefficient"));
        resize_coefficient->setGeometry(QRect(100, 50, 121, 21));
        resize_coefficient->setValue(20);
        resize_coefficient->setOrientation(Qt::Horizontal);
        textBrowser_6 = new QTextBrowser(Basic);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(40, 50, 51, 23));
        textBrowser_6->setFont(font);
        RGB_R = new QPushButton(Basic);
        RGB_R->setObjectName(QStringLiteral("RGB_R"));
        RGB_R->setGeometry(QRect(10, 130, 75, 25));
        RGB_G = new QPushButton(Basic);
        RGB_G->setObjectName(QStringLiteral("RGB_G"));
        RGB_G->setGeometry(QRect(90, 130, 75, 25));
        RGB_B = new QPushButton(Basic);
        RGB_B->setObjectName(QStringLiteral("RGB_B"));
        RGB_B->setGeometry(QRect(170, 130, 75, 25));
        tabWidget->addTab(Basic, QString());
        Advanced = new QWidget();
        Advanced->setObjectName(QStringLiteral("Advanced"));
        pushButton = new QPushButton(Advanced);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 113, 32));
        tabWidget->addTab(Advanced, QString());
        History = new QWidget();
        History->setObjectName(QStringLiteral("History"));
        tabWidget->addTab(History, QString());
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-20, 180, 811, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 796, 23));
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
        PictureHistogram->setText(QApplication::translate("MainWindow", "Select a picture first", Q_NULLPTR));
        resize_button->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\216\213\347\274\251", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\261\202\351\200\232\351\201\223\346\217\220\345\217\226\357\274\232", Q_NULLPTR));
        sobel_picture->setText(QApplication::translate("MainWindow", " \345\233\276\345\203\217\351\224\220\345\214\226", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\344\272\256\345\272\246\350\260\203\346\225\264", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\257\271\346\257\224\345\272\246\350\260\203\346\225\264", Q_NULLPTR));
        blur_picture->setText(QApplication::translate("MainWindow", " \345\233\276\345\203\217\346\250\241\347\263\212", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "\346\274\253\346\260\264\345\241\253\345\205\205", Q_NULLPTR));
        rotate_picture->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\346\227\213\350\275\254", Q_NULLPTR));
        gray_picture->setText(QApplication::translate("MainWindow", "\350\275\254\344\270\272\347\201\260\345\272\246\345\233\276", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "\347\273\230\345\233\276", Q_NULLPTR));
        textBrowser_4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Apple LiGothic'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\275\223\345\211\215\345\244\247\345\260\217</span></p></body></html>", Q_NULLPTR));
        pic_size->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Apple LiGothic'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:13pt;\"><br /></p></body></html>", Q_NULLPTR));
        textBrowser_6->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Apple LiGothic'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\345\200\215\347\216\207</span></p></body></html>", Q_NULLPTR));
        RGB_R->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        RGB_G->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        RGB_B->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Basic), QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\212\237\350\203\275", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Advanced), QApplication::translate("MainWindow", "\351\253\230\347\272\247\345\212\237\350\203\275", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(History), QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\216\206\345\217\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
