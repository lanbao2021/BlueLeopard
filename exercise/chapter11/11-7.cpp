// 11-7.cpp
// Created by 蓝同学 on 2021/9/5.
//
#include <ostream>
using namespace std;

class integral{
    enum{ numOfCalc=1000 }; // 小矩形的个数
    double (*f)(double); // 函数作为参数
public:
    integral(double (*g)(double)):f(g){}
    double operator()(double a, double b);
};

double integral::operator()(double a, double b) {
    double sum=0, dlt = (b-a) /numOfCalc;
    for(double h=a+dlt/2; h<b; h+=dlt)
        sum += dlt*f(h);
    return sum;
}

int main(){
    return 0;
}
