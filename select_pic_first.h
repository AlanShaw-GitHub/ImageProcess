#ifndef SELECT_PIC_FIRST_H
#define SELECT_PIC_FIRST_H

#include <QDialog>

namespace Ui {
class Select_pic_first;
}

class Select_pic_first : public QDialog
{
    Q_OBJECT

public:
    explicit Select_pic_first(QWidget *parent = 0);
    ~Select_pic_first();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Select_pic_first *ui;
};

#endif // SELECT_PIC_FIRST_H
