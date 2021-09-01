// 3-1.cpp
// Created by 蓝同学 on 2021/7/5.
// 从键盘输入3个整数，输出其中的最大值、最小值和平均值
#include <iostream>
using namespace std;
int main()
{
    double avg;
    int num1, num2, num3, max, min;
    cout << "请输入3个整数：";
    cin >> num1 >> num2 >> num3;

    max = min = num1;
    if(num2 > max) max = num2;
    if(num2 < min) min = num2;
    if(num3 > max) max = num3;
    if(num3 < min) min = num3;
    avg = (num1 + num2 + num3)/3.0;

    cout << "最大值：" << max << endl;
    cout << "最小值：" << min << endl;
    cout << "平均值" << avg << endl;

    return 0;
}

