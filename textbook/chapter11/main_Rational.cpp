// main_operator.cpp
// Created by 蓝同学 on 2021/9/3.
//
#include "Rational_Operator.cpp"

int main(){
    Rational r1, r2, r3, r4;
    double x;

    cout << "input r1:";
    cin >> r1;
    cout << "input r2:";
    cin >> r2;

    r3 = r1 + r2;
    cout << r1 << "+" << r2 << "=" << r2 << endl;

    r3 = r1 * r2;
    cout << r1 << "*" << r2 << "=" << r3 << endl;

    r4 = (r1 + r2) * r3;
    cout << "(r1+r2)*r3 = " << r4 << endl;

    x = 5.5 - r1;
    cout << "5.5 - r1 = " << x << endl;
    cout << (r1 < r2 ? r1 : r2) << endl;

    return 0;
}
