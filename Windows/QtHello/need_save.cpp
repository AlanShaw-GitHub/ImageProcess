#include "need_save.h"
#include "ui_need_save.h"

need_save::need_save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::need_save)
{
    ui->setupUi(this);
}

need_save::~need_save()
{
    delete ui;
}
