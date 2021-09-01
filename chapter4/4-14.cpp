// 4-14.cpp
// Created by 蓝同学 on 2021/8/15.
//
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, root, epsilon;
    cout << "input the x=";
    cin >> x;
    cout << "input the epsilon=";
    cin >> epsilon;
    root = x/2;
    while(fabs(root*root-x) > epsilon){
        root = (root + x/root)/2;
    }
    cout << "the root of x = " << root << endl;
    return 0;
}

