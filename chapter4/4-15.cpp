// 4-15.cpp
// Created by 蓝同学 on 2021/8/15.
//
#include <iostream>
using namespace std;
double f(double x){
    double fx;
    fx = x*x + 5*x + 1;
    return fx;
}
int main(){
    double a, b, delta, area;
    area = 0;
    cout << "input delta = ";
    cin >> delta;
    cout << "input a = ";
    cin >> a;
    cout << "input b = ";
    cin >> b;
    for (a = 0; a <= b; a += delta){
        area += delta*f(a + delta/2);
    }
    return 0;
}
