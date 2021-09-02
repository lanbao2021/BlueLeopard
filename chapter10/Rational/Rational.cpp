// Rational.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include "Rational.h"

void Rational::add(const Rational &r1, const Rational &r2) {
    num = r1.num * r2.den + r2.num * r1.den;
    den = r1.den * r2.den;
    ReductFraction();
}

void Rational::multi(const Rational &r1, const Rational &r2) {
    num = r1.num * r2.num;
    den = r1.den * r2.den;
    ReductFraction();
}

void Rational::ReductFraction() {
    int tmp = (num>den) ? den : num; // 肯定是分子分母中比较小的一方开始遍历搜索
    for(; tmp > 1; --tmp) // 不考虑负分数
        // 找出num和den的最大公因子，让他们分别除以最大公因子
        if(num % tmp == 0 && den % tmp ==0){
            num /= tmp;
            den /= tmp;
            break; // 找到最大公因子就可以结束了
        }
}

void Rational::substract(const Rational &r1, const Rational &r2) {
    num = r1.num * r2.den - r2.num * r1.den;
    den = r1.den * r2.den;
    ReductFraction();
}

void Rational::divide(const Rational &r1, const Rational &r2) {
    num = r1.num * r2.den;
    den = r1.den * r2.num;
    ReductFraction();
}

double Rational::getDouble() const{
    return double(num) / den;
}
