// 10-7.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
using namespace std;

class complex{
private:
    double real;
    double imag;
public:
    complex(double r=0, double i=0):real(r), imag(i){}
    void input();
    void output() const;
    void add(const complex &d1, const complex &d2);
    void multi(const complex &d1, const complex &d2);
};

void complex::input(){
    cout << "input the real:";
    cin >> real;
    cout << "input the imag:";
    cin >> imag;
}

void complex::output() const {
    cout << "( " << real << " + " << imag << "i )" ;
}

void complex::add(const complex &d1, const complex &d2) {
    real = d1.real + d2.real;
    imag = d1.imag + d2.imag;
}

void complex::multi(const complex &d1, const complex &d2) {
    real = d1.real * d2.real - d1.imag * d2.imag;
    imag = d1.imag * d2.real + d1.real * d2.imag;
}
int main(){
    return 0;
}