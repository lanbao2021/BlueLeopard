// 2-8.cpp
// Created by 蓝同学 on 2021/7/5.
// 设计并实现一个银行计算利息的程序。
// 输入为存款金额和存款年限，输出为存款的本利之和。
// 假设年利率为1.2%，计算存款本利之和公式为：本金 + 本金 * 年利率 * 存款年限。
#include <iostream>
using namespace std;
int main()
{
    const double RATE = 1.2;
    double principal;
    int years;

    cout << "请输入本金和存款年限";
    cin >> principal >> years;

    principal = principal + principal * RATE * years / 100;

    cout << "你的本利和是：" << principal << endl;
    return 0;
}

