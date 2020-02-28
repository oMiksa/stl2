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
    QVector<QString> elemnts;

    parser();
    parser(QString);
    void run();
    void show();

};

#endif // PARSER_H
