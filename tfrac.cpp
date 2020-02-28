#include "tfrac.h"
#include "tfrac.h"

int TFrac::getF()
{
    return  first;
}

int TFrac::getS()
{
    return second;
}

QString TFrac::show()
{
    return QString::number(first) + "/" + QString::number(second);
}

void TFrac::swap()
{
    int temp = first;
    first = second;
    second = temp;
}

QString TFrac::toString()
{
    return QString::number(first) + "/" + QString::number(second);
}

TFrac::TFrac()
{
    first = 0;
    second = 1;
}

TFrac::TFrac(QString str)
{
    QStringList temp(str.split('/', QString::SkipEmptyParts));
    first = temp.at(0).toInt();
    second = temp.at(1).toInt();
}

TFrac::TFrac(int a, int b)
{
    first = a;
    second = b;
}

bool TFrac::sokr(int n)
{
    if (!(first % n) && !(second % n)) {
        first = first / n;
        second = second / n;
        return true;
    } else return false;
}

int TFrac::gcd_m(int a,int b){
    while (a && b)
        if (a > b) a%=b;
        else b%=a;
    return a+b;
}

TFrac TFrac::operator+(TFrac temp)
{
    int a = this->first*temp.second + temp.first*this->second;
    int b = temp.second * this->second;
    return TFrac(a, b);
}

TFrac TFrac::operator-(TFrac temp)
{
    int b = gcd_m(temp.second, this->second);
    int a = this->first*b/this->second + temp.first*b/temp.second;
    return TFrac(a, b);
}

TFrac TFrac::operator*(TFrac temp)
{
    int a = this->first*temp.first;
    int b = temp.second * this->second;
    return TFrac(a, b);
}

TFrac TFrac::operator/(TFrac temp)
{
    temp.swap();
    return (this->operator*(temp));
}

void TFrac::operator+=(TFrac temp)
{
    this->first = this->first*temp.second + temp.first*this->second;
    this->second = temp.second * this->second;
}

bool TFrac::operator<(TFrac temp)
{
    int a = this->first * temp.second;
    int b = temp.first * this->second;
    return a < b;
}

bool TFrac::operator>(TFrac temp)
{
    int a = this->first * temp.second;
    int b = temp.first * this->second;
    return a > b;
}

bool TFrac::operator==(TFrac temp)
{
    return (this->first / this->second) == (temp.first / temp.second);
}
