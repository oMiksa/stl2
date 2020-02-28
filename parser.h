#ifndef PARSER_H
#define PARSER_H
#include <QString>
#include <QVector>
#include <QPair>
#include <QDebug>

class parser
{
private:
    QString SIM;
    QString in_str;


public:
    QVector<QString> elemnts, elemnts2;

    parser();
    parser(QString);
    void run();
    void run2();
    void con();
    void copy();
    void show();

    void show2();
};

#endif // PARSER_H
