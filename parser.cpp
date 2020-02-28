#include "parser.h"

parser::parser()
{
    SIM = "+-*/";
}

parser::parser(QString str)
{
    in_str = str;
    SIM = "-+*/";
}

void parser::run()
{
    QString number;
    for(auto it = in_str.rbegin(); it != in_str.rend(); it++) {
        if (*it == " ") {
            elemnts.push_front(number);
            number.clear();
        } else {
            number = *it + number;
        }
    }
}

void parser::run2()
{
    QString number;
    for(auto it = in_str.rbegin(); it != in_str.rend(); it++) {
        if (SIM.count(*it)) {
            if (!number.isEmpty()) {
                elemnts.push_front(number);
                number.clear();
            }
            elemnts.push_front(QString(*it));
        } else {
            number = *it + number;
        }
    }
}

void parser::con()
{
    for (auto it = elemnts.rbegin(); it != elemnts.rend(); it++) {
        if (*it == "-") {
            if (SIM.indexOf((*(it-1))[0]) == -1) {
                *it =  *it + *(it-1);
                *(it-1) = " ";
            }
        }
    }
}

void parser::copy()
{
    for (auto it = elemnts.begin(); it != elemnts.end();it++) {
        if (*it != " ")
            elemnts2.push_back(*it);
    }
}

void parser::show()
{
    for (auto i = elemnts.begin(); i != elemnts.end(); i++) {
        qDebug() << *i << endl;
    }
}

void parser::show2()
{
    for (auto i = elemnts2.begin(); i != elemnts2.end(); i++) {
        qDebug() << *i << endl;
    }
}
