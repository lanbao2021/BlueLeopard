// 4-5.cpp
// Created by 蓝同学 on 2021/8/8.
// 输入fibonacci前的0～15位数字
#include <iostream>
using namespace std;
int main(){
    int n1, n2;
    n1 = 0;
    n2 = 1;
    int tmp;
    cout << n1 << "," << n2 << ",";
    for(int num=3; num<=15; num++){
        cout << n2 + n1 << ",";
        tmp = n2;
        n2 = n2 + n1;
        n1 = tmp;
    }
    return 0;
}

