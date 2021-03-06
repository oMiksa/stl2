#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>
#include <QValidator>
#include <QRegExp>
#include "tfrac.h"
#include "parser.h"
#include "dialog_inf.h"
#include "ui_dialog_inf.h"
#include "editor.h"

#define ADD 1
#define MULT 2
#define DIV 3
#define SUB 4


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_n7_clicked();

    void on_pushButton_ADD_clicked();

    void on_pushButton_MULT_clicked();

    void on_pushButton_DIV_clicked();

    void on_pushButton_SUB_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_n0_clicked();

    void on_pushButton_n8_clicked();

    void on_pushButton_n9_clicked();

    void on_pushButton_n4_clicked();

    void on_pushButton_n5_clicked();

    void on_pushButton_n6_clicked();

    void on_pushButton_n3_clicked();

    void on_pushButton_n2_clicked();

    void on_pushButton_n1_clicked();

    void on_pushButton_C_clicked();

    void on_pushButton_BS_clicked();

    void on_pushButton_Result_clicked();

    void on_actionInformation_triggered();

    void on_pushButton_plus_mins_clicked();

private:
    QValidator *valid;
    int pos;
    editor *ed;
    TFrac *dr1, *dr2;
    int status;

    Ui::MainWindow *ui;
    void init();
};

#endif // MAINWINDOW_H
