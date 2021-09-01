// 2-6.cpp
// Created by 蓝同学 on 2021/7/5.
// 输入一个字符，输出它的ASCII值
#include <iostream>
using namespace std;
int main()
{
    char ch;

    cout << "请输入一个字符：";
    cin >> ch;

    cout << static_cast<int>(ch) << endl;
    return 0;
}

