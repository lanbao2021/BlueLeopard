// Rational.h
// Created by 蓝同学 on 2021/9/2.
//

#ifndef BLUELEOPARD_RATIONAL_H
#define BLUELEOPARD_RATIONAL_H

#include <iostream>
using namespace std;
class Rational{
private:
    int num; // 分子
    int den; // 分母
    void ReductFraction(); //将有理数化简成最简形式
public:
    void create(int n, int d){
        num = n;
        den = d;
        ReductFraction();
    }
    void add(const Rational &r1, const Rational &r2);
    void multi(const Rational &r1, const Rational &r2);
    void display(){ cout << num << '/' << den; }
    void substract(const Rational &r1, const Rational &r2);
    void divide(const Rational &r1, const Rational &r2);
    void getDouble() const;
};
#endif //BLUELEOPARD_RATIONAL_H
