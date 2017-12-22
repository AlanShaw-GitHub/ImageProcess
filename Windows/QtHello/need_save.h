#ifndef NEED_SAVE_H
#define NEED_SAVE_H

#include <QDialog>

namespace Ui {
class need_save;
}

class need_save : public QDialog
{
    Q_OBJECT

public:
    explicit need_save(QWidget *parent = 0);
    ~need_save();

private:
    Ui::need_save *ui;
};

#endif // NEED_SAVE_H
