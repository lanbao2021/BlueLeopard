// 2-10.cpp
// Created by 蓝同学 on 2021/7/5.
// 写一个程序，输出在你使用的C++系统中int类型的数据占几个字节，double类型的数据占几个字节，short int占几个字节，float类型占几个字节。
#include <iostream>
using namespace std;
int main()
{
    cout << "int型占用了" << sizeof(int) << "个字节" << endl;
    cout << "double型占用了" << sizeof(double) << "个字节" << endl;
    cout << "short int型占用了" << sizeof(short int) << "个字节" << endl;
    cout << "float型占用了" << sizeof(float) << "个字节" << endl;
    return 0;
}
