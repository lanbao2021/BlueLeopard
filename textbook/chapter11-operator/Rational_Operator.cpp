// Rational_Operator.cpp
// Created by 蓝同学 on 2021/9/3.
//
#include "Rational_Operator.h"

Rational operator+(const Rational &r1, const Rational &r2){
    Rational tmp;

    tmp.num = r1.num * r2.den + r2.num * r1.den;
    tmp.den = r1.den * r2.den;
    tmp.ReductFraction();
    return tmp;
}

Rational operator*(const Rational &r1, const Rational &r2){
    Rational tmp;
    tmp.num = r1.num * r2.num;
    tmp.den = r1.den * r2.den;
    tmp.ReductFraction();
    return tmp;
}

void Rational::ReductFraction() {
    int tmp = (num>den) ? den : num;
    for (; tmp>1; --tmp)
        if(num % tmp == 0 && den % tmp ==0){
            num /= tmp;
            den /= tmp;
            break;
        }
}

istream &operator>>(istream &in, Rational &obj){
    in >> obj.num >> obj.num;
    obj.ReductFraction();
    return in;
}

ostream &operator<<(ostream &os, const Rational &obj){
    os << obj.num << '/' << obj.den;
    return os;
}

bool operator<(const Rational &r1, const Rational &r2){
    return r1.num * r2.den < r1.den * r2.num;
}

bool operator==(const Rational &r1, const Rational &r2){
    return r1.num == r2.num && r1.den == r2.den;
}

