// 2-5.cpp
// Created by 蓝同学 on 2021/7/5.
// 编写一个程序用于水果店售货员结账。已知苹果每斤2.50元，鸭梨每斤1.80元，香蕉每斤2元，橘子每斤1.60元。
// 要求输入各种水果的重量，打印应付金额，再输入顾客付款数，打印应找零的金额。
#include <iostream>
using namespace std;
int main()
{
    const double price_apple = 2.50;
    const double price_pear = 1.80;
    const double price_banana = 2.00;
    const double price_orange = 1.60;

    double apple, pear, banana, orange;
    double money, income, change;

    cout << "请输入苹果、梨、香蕉、橘子的重量：";
    cin >> apple >> pear >> banana >> orange;

    money = apple * price_apple + pear*price_pear + banana*price_banana + orange*price_orange;
    cout << "你应付" << money << "元" << endl;
    cin >> income;
    change = income - money;
    cout << "\n找零" << change << "元" << endl;
    return 0;
}


