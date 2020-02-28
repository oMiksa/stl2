#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ed;
}

void MainWindow::on_pushButton_n7_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("7"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("7"));
}

void MainWindow::on_pushButton_ADD_clicked()
{
    QString first(ui->lineEdit->text());
    if (valid->validate(first, pos) == 2) {
        ed->set_action("+");
        ed->set_oper_first(first);
        ui->lineEdit->setText("");
    }
}

void MainWindow::on_pushButton_MULT_clicked()
{
    QString first(ui->lineEdit->text());
    if (valid->validate(first, pos) == 2) {
        ed->set_action("*");
        ed->set_oper_first(first);
        ui->lineEdit->setText("");
    }}

void MainWindow::on_pushButton_DIV_clicked()
{
    QString first(ui->lineEdit->text());
    if (valid->validate(first, pos) == 2) {
        ed->set_action("/");
        ed->set_oper_first(first);
        ui->lineEdit->setText("");
    }
}

void MainWindow::on_pushButton_SUB_clicked()
{
    QString first(ui->lineEdit->text());
    if (valid->validate(first, pos) == 2) {
        ed->set_action("-");
        ed->set_oper_first(first);
        ui->lineEdit->setText("");
    }
}

void MainWindow::on_pushButton_point_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("/"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("/"));
}

void MainWindow::on_pushButton_n0_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("0"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("0"));
}

void MainWindow::on_pushButton_n8_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("8"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("8"));
}

void MainWindow::on_pushButton_n9_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("9"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("9"));
}

void MainWindow::on_pushButton_n4_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("4"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("4"));
}

void MainWindow::on_pushButton_n5_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("5"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("5"));
}

void MainWindow::on_pushButton_n6_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("6"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("6"));
}

void MainWindow::on_pushButton_n3_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("3"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("3"));
}

void MainWindow::on_pushButton_n2_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("2"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("2"));
}

void MainWindow::on_pushButton_n1_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("1"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("1"));
}

void MainWindow::on_pushButton_C_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_BS_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().left(ui->lineEdit->text().length() - 1));
}

void MainWindow::on_pushButton_Result_clicked()
{
    QString second(ui->lineEdit->text());
    if (valid->validate(second, pos) == 2) {
        ed->set_oper_second(second);
        ui->lineEdit->setText(ed->get_resoult());
    }
}

void MainWindow::init()
{
    ed = new editor();
    QRegExp rx("(^-{0,1}[0-9]{1,4}/[1-9][0-9]{0,3}$)");
    valid = new QRegExpValidator(rx, this);
    ui->lineEdit->setValidator(valid);
}

void MainWindow::on_actionInformation_triggered()
{
    Ui::Dialog_inf d;
    QDialog *f_d = new QDialog;
    d.setupUi(f_d);
    f_d->show();
}

void MainWindow::on_pushButton_plus_mins_clicked()
{
    if (ui->lineEdit->text().indexOf("-") == -1) {
        ui->lineEdit->setText("-" + ui->lineEdit->text());
    } else {
        ui->lineEdit->setText(ui->lineEdit->text().right(ui->lineEdit->text().length() - 1));
    }
}
