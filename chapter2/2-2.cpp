// 2-2.cpp
// Created by 蓝同学 on 2021/7/5.
// 输入两个整型数，输出这两个整型数相除后的商和余数
#include <iostream>
using namespace std;
int main()
{
    int num1, num2, quotient, remainder;

    cout << "请输入两个整型数";
    cin >> num1 >> num2;

    quotient = num1 / num2; // 计算商
    remainder = num1 % num2; // 计算余数

    cout << num1 << "/" << num2 << "的商为：" << quotient << endl;
    cout << num1 << "%" << num2 << "的余数为：" << remainder << endl;

    return 0;
}


