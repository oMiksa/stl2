#ifndef TFRAC_H
#define TFRAC_H
#include <iostream>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <deque>

using namespace std;

class TFrac
{
private:
    int first;
    int second;
public:
    int getF();
    int getS();
    QString show();
    void swap();
    QString toString();
    TFrac();
    TFrac(QString str);
    TFrac(int a, int b);
    bool sokr(int);
    TFrac operator+(TFrac temp);
    void operator+=(TFrac temp);
    bool operator<(TFrac temp);
    bool operator>(TFrac temp);
    bool operator==(TFrac temp);
    TFrac operator -(TFrac temp);
    TFrac operator *(TFrac temp);
    TFrac operator /(TFrac temp);
    int gcd_m(int a, int b);
};

static bool com(TFrac a, TFrac b) {
    return a < b;
}

class InOutDo {
private:
    deque<TFrac> arr;


public:
    InOutDo () {}
    void Input(TFrac a) {
        arr.push_back(a);
    }
    QString OutPut(){
        QString str;
        for (deque<TFrac>::iterator it = arr.begin(); it != arr.end(); it++) {
            str.append(it->toString() + " ");
        }
        return str;
    }
    TFrac Sum() {
        TFrac x;
        for (deque<TFrac>::iterator it = arr.begin(); it != arr.end(); it++) {
            x+=*it;
        }
        return x;
    }
    void SortUp() {
        sort(arr.begin(), arr.end(), com);
    }
    void SortDown() {
        sort(arr.rbegin(), arr.rend(), com);
    }
};

#endif // TFRAC_H
