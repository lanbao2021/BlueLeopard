// 15-1.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
#include <cmath>
using namespace std;

class noRoot{};
class divByZero{};

double Sqrt(double x){
    if(x < 0)
        throw noRoot(); // 表示调用默认构造函数生成一个对象
    return sqrt(x);
}

double div(double x, double y){
    if(y == 0)
        throw divByZero();
    return x/y;
}

int main(){

    double a, b, c, x1, x2, dlt;

    cout << "input 3 args:" << endl;
    cin >> a >> b >> c;
    try{
        dlt = Sqrt(b*b - 4*a*c);
        x1 = div(-b + dlt, 2*a);
        x2 = div(-b - dlt, 2*a);
        cout << "x1 = " << x1 << "， x2 = " << x2 << endl;
    }
    catch(noRoot){ cout << "no root!" << endl; }
    catch(divByZero) { cout << "不是一元二次方程" << endl; }

    return 0;
}
