#include "select_pic_first.h"
#include "ui_select_pic_first.h"
#include "mainwindow.h"

Select_pic_first::Select_pic_first(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_pic_first)
{
    ui->setupUi(this);
}

Select_pic_first::~Select_pic_first()
{
    delete ui;
}

void Select_pic_first::on_buttonBox_accepted()
{
}
