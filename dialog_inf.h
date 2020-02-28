#ifndef DIALOG_INF_H
#define DIALOG_INF_H

#include <QDialog>

namespace Ui {
class Dialog_inf;
}

class Dialog_inf : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_inf(QWidget *parent = nullptr);
    ~Dialog_inf();

private:
    Ui::Dialog_inf *ui;
};

#endif // DIALOG_INF_H
