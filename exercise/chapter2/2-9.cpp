// 2-9.cpp
// Created by 蓝同学 on 2021/7/5.
// 编写一个程序读入4个整数，输出它们的平均值
#include <iostream>
using namespace std;
int main()
{
    double avg;
    int num1, num2, num3, num4;

    cout << "请输入4个数";
    cin >> num1 >> num2 >> num3 >> num4;
    avg = (num1 + num2 + num3 + num4) / 4.0;
    cout << "4个数的平均值是：" << avg << endl;
    return 0;
}

