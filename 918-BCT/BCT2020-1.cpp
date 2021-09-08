// BCT2020-1.cpp
// Created by 蓝同学 on 2021/9/8.
// 计算sinx
#include <iostream>
#include <cmath>
using namespace std;

double Sin(double x, double epsilon = 1e-6){
    double sin = 0, item = x;
    for(int i=2; fabs(item) > epsilon; ++i){
        sin += item;
        item = -item * x * x / (2 * i - 1) / (2 * i - 2);
    }
    return sin;
}

int main(){
    return 0;
}

