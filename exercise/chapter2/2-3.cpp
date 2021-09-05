// 2-3.cpp
// Created by 蓝同学 on 2021/7/5.
// 输入9个小于8位的整型数，然后按3行打印，每一列都要对齐。
// 例如：输入，1、2、3、11、22、33、111、222、333，输出为...
#include <iostream>
using namespace std;
int main()
{
    int num1, num2, num3, num4, num5, num6, num7, num8, num9;

    cout<< "请输入9个整数";
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9;

    cout << num1 << '\t' << num2 << '\t' << num3 << endl;
    cout << num4 << '\t' << num5 << '\t' << num6 << endl;
    cout << num7 << '\t' << num8 << '\t' << num9 << endl;
    return 0;
}


