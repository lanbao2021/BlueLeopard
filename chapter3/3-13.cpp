// 3-13.cpp
// Created by 蓝同学 on 2021/7/5.
// 二维平面上的一个与x轴平行的矩形可以用两个点来表示。
// 这两个点分别表示矩形的 左下方和右上方的两个角。
// 编一程序，输入两个点(x1，y1)、(x2，y2)
// 计算它对应的矩形的面积和周长，并判断该矩形是否是一个正方形。
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1, x2, y1, y2;
    const double EPSILON = 1e-10;

    cout << "请输入左下角的坐标(x1,y1)" << endl;
    cin >> x1 >> y1;
    cout << "请输入右上角的坐标(x2,y2)" << endl;
    cin >> x2 >> y2;

    cout << "矩形的面积为：" << fabs((y2-y1) * (x2-x1)) << endl;
    cout << "矩形的周长为：" << fabs(2*(y2 - y1 + x2 - x1)) << endl;
    cout << (fabs(y2 - y1 - x2 + x1) < EPSILON ? "是正方形" : "不是正方形") << endl;

    return 0;
}

