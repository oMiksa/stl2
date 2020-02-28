#include "dialog_inf.h"
#include "ui_dialog_inf.h"

Dialog_inf::Dialog_inf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_inf)
{
    ui->setupUi(this);
}

Dialog_inf::~Dialog_inf()
{
    delete ui;
}
