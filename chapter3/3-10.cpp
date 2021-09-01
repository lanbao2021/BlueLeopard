// 3-10.cpp
// Created by 蓝同学 on 2021/7/5.
// 编写一个程序，输入三个非0正整数，判断这三个值是否能够成一个三角形
// 如果能，进一步判断是否为直角三角形
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, tmp;
    cout << "请输入三角形的三条边长：" << endl;
    cin >> a >> b >> c ;

    // 将三条边长按递减次序排序, a最大，c最小
    if(a<b) { tmp = a; a = b; b = tmp; }
    if(a<c) { tmp = a; a = c; c = tmp; }

    // 判断三角形
    if(b+c > a)
    {
        if(a*a == b*b + c*c)
            cout << "是三角形且为直角三角形" << endl;
        else
            cout << "是三角形，但不是直角三角形" << endl;
    }
    else
        cout << "不能构成三角形" << endl;
    return 0;
}

