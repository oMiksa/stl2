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
}

void MainWindow::on_pushButton_n7_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("7"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("7"));
}

void MainWindow::on_pushButton_ADD_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("+"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("+"));
}

void MainWindow::on_pushButton_MULT_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("*"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("*"));
}

void MainWindow::on_pushButton_DIV_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("/"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("/"));
}

void MainWindow::on_pushButton_SUB_clicked()
{
    if (valid->validate(ui->lineEdit->text().append("-"), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append("-"));
}

void MainWindow::on_pushButton_point_clicked()
{
    if (valid->validate(ui->lineEdit->text().append(" "), pos))
        ui->lineEdit->setText(ui->lineEdit->text().append(" "));
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
    QString str(ui->lineEdit->text());
    if (valid->validate(str, pos) != 2) {
        ui->lineEdit->setText("ERROR");
    } else {
        parser p(" " + str);
        p.run();
        //p.show();

        TFrac dr1(p.elemnts.at(0).toInt(), p.elemnts.at(2).toInt());
        TFrac dr2(p.elemnts.at(4).toInt(), p.elemnts.at(6).toInt());
        TFrac res;

        if (p.elemnts.at(3) == "+")
            res = (dr1+dr2);
        if (p.elemnts.at(3) == "-")
            res = (dr1-dr2);
        if (p.elemnts.at(3) == "*")
            res = (dr1*dr2);
        if (p.elemnts.at(3) == "/")
            res = (dr1/dr2);
        bool test = true;
        while (test) {
            test = false;
            test += res.sokr(5);
            test += res.sokr(3);
            test += res.sokr(2);
        }
        if (res.getS() == 1)
            ui->lineEdit->setText(QString::number(res.getF()));
        else ui->lineEdit->setText(res.show());
    }
}

void MainWindow::init()
{
    QRegExp rx("(^-{0,1}[0-9]{1,4} / -{0,1}[1-9][0-9]{0,3} [-+*/]{1,1} -{0,1}[0-9]{1,4} / -{0,1}[1-9][0-9]{0,3}$)");
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
