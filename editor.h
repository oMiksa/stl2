#ifndef EDITOR_H
#define EDITOR_H

#include "tfrac.h"

enum action{ERROR, ADD, SUB, MULT, DIV};

class editor
{
private:
    action act;
    TFrac *dr1, *dr2, *result;

public:
    editor();
    ~editor();
    void set_action(QString);
    void set_oper_first(QString);
    void set_oper_second(QString);
    void run();
    QString get_resoult();
    void sokr();
};

#endif // EDITOR_H
