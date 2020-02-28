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

void parser::show()
{
    for (auto i = elemnts.begin(); i != elemnts.end(); i++) {
        qDebug() << *i << endl;
    }
}
