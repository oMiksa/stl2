#include "editor.h"

editor::editor()
{

}

editor::~editor()
{
    delete dr1;
    delete dr2;
}

void editor::set_action(QString str)
{
    switch(QString("-+*/").indexOf(str)) {
        case 0: act = SUB; break;
        case 1: act = ADD; break;
        case 2: act = MULT; break;
        case 3: act = DIV; break;
        default: act = ERROR;
    }
}

void editor::set_oper_first(QString str)
{
    dr1 = new TFrac(str);
}

void editor::set_oper_second(QString str)
{
    dr2 = new TFrac(str);
}

void editor::run()
{
    if (act == ADD) result = new TFrac(*dr1 + *dr2);
    if (act == SUB) result = new TFrac(*dr1 - *dr2);
    if (act == MULT)result = new TFrac(*dr1 * *dr2);
    if (act == DIV) result = new TFrac(*dr1 / *dr2);
}

QString editor::get_resoult()
{
    run();
    sokr();

    if (abs(result->getF()) == abs(result->getS()))
        return QString::number(result->getF() / result->getS());
    if (result->getS() == 1)
        return QString::number(result->getF());
    return result->show();
}

void editor::sokr()
{
    if (result->getF() < 0 && result->getS() < 0) {
        result->setF(abs(result->getF()));
        result->setS(abs(result->getS()));
    }

    bool st = true;
    while (st) {
        st = false;
        st += result->sokr(5);
        st += result->sokr(3);
        st += result->sokr(2);
    }
}
