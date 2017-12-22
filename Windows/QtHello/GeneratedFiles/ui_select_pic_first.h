/********************************************************************************
** Form generated from reading UI file 'select_pic_first.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_PIC_FIRST_H
#define UI_SELECT_PIC_FIRST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Select_pic_first
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Select_pic_first)
    {
        if (Select_pic_first->objectName().isEmpty())
            Select_pic_first->setObjectName(QStringLiteral("Select_pic_first"));
        Select_pic_first->resize(400, 130);
        buttonBox = new QDialogButtonBox(Select_pic_first);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 90, 331, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        plainTextEdit = new QPlainTextEdit(Select_pic_first);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 20, 371, 51));
        QFont font;
        font.setFamily(QStringLiteral("Apple Color Emoji"));
        font.setPointSize(18);
        plainTextEdit->setFont(font);

        retranslateUi(Select_pic_first);
        QObject::connect(buttonBox, SIGNAL(accepted()), Select_pic_first, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Select_pic_first, SLOT(reject()));

        QMetaObject::connectSlotsByName(Select_pic_first);
    } // setupUi

    void retranslateUi(QDialog *Select_pic_first)
    {
        Select_pic_first->setWindowTitle(QApplication::translate("Select_pic_first", "Error", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("Select_pic_first", "Please first select a picture!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Select_pic_first: public Ui_Select_pic_first {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_PIC_FIRST_H
