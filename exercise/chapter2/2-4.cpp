// 2-4.cpp
// Created by 蓝同学 on 2021/7/5.
// 某工种按小时计算工资。每月劳动时间（小时）乘以每小时工资等于总工资。总工资扣除10%的公积金，剩余的为应发工资。
// 编写一个程序从键盘输入劳动时间和每小时工资，输出应发工资
#include <iostream>
using namespace std;
int main()
{
    int time, yuanPerHour, totalSalary, salary;

    cout << "请输入每小时工资：";
    cin >> yuanPerHour;
    cout << "请输入本月劳动时间:" << endl;
    cin >> time;

    totalSalary = time * yuanPerHour;
    salary = totalSalary - 0.1*totalSalary;

    cout << "本月应得工资为：" << salary << endl;
    return 0;
}

