// Rational_Operator.h
// Created by 蓝同学 on 2021/9/3.
//

#ifndef BLUELEOPARD_RATIONAL_OPERATOR_H
#define BLUELEOPARD_RATIONAL_OPERATOR_H

#include <iostream>
using namespace std;
class Rational{
    friend istream &operator>>(istream &in, Rational &obj); // 输入重载函数
    friend ostream &operator<<(ostream &os, const Rational &obj); // 输出重载函数
    friend Rational operator+(const Rational &r1, const Rational &r2);
    friend Rational operator*(const Rational &r1, const Rational &r2);
    friend bool operator<(const Rational &r1, const Rational &r2);
    friend bool operator==(const Rational &r1, const Rational &r2);
    // 友元声明放在private和public都一样
private:
    int num; // 分子
    int den; // 分母
    void ReductFraction(); // 分数化简
public:
    Rational(int n=0, int d=1){ num=n; den=d; ReductFraction(); }
    operator double () const { return double(num)/den; } // Rational类型到double类型的隐式转换
};

#endif //BLUELEOPARD_RATIONAL_OPERATOR_H
