// 3-4.cpp
// Created by 蓝同学 on 2021/7/5.
// 有一个函数，其定义如下。。。编一程序，输入x，输出y。
#include <iostream>
using namespace std;
int main()
{
    double x,y;

    cout << "请输入x：";
    cin >> x;

    if(x < 1)
        y = x;
    else if(x < 10)
        y = 2 * x - 1;
    else
        y = 3 * x - 11;

    cout << "y = " << y << endl;
    return 0;
}
