/********************************************************************************
** Form generated from reading UI file 'need_save.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEED_SAVE_H
#define UI_NEED_SAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_need_save
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *need_save)
    {
        if (need_save->objectName().isEmpty())
            need_save->setObjectName(QStringLiteral("need_save"));
        need_save->resize(400, 130);
        buttonBox = new QDialogButtonBox(need_save);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 90, 331, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(need_save);
        QObject::connect(buttonBox, SIGNAL(accepted()), need_save, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), need_save, SLOT(reject()));

        QMetaObject::connectSlotsByName(need_save);
    } // setupUi

    void retranslateUi(QDialog *need_save)
    {
        need_save->setWindowTitle(QApplication::translate("need_save", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class need_save: public Ui_need_save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEED_SAVE_H
