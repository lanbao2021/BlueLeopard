// 4-16.cpp
// Created by 蓝同学 on 2021/8/15.
//
#include <iostream>
#include <cmath>
using namespace std;

double fx(double x)
{
    double f = sqrt(1-x*x);
    return f;
}
int main(){
    double x, a, b, delta, area;
    delta = 0.01;
    a = 0;
    b = 1;
    area = 0;
    for (x=a; x<=b; x+=delta){
        area += delta*fx(x + delta/2);
    }
    cout << "the area of radius(1) = " << 4*area << endl;
    return 0;
}

