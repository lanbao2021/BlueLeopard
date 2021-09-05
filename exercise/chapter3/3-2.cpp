// 3-2.cpp
// Created by 蓝同学 on 2021/7/5.
// 输入一个整型数，判断输入的整型数是奇数还是偶数(三元运算符）
#include <iostream>
using namespace std;
int main()
{
    int num;

    cout << "请输入一个整数：" ;
    cin >> num;
    cout << num << (num % 2 ? "是奇数" : "是偶数") << endl;
    return 0;
}

