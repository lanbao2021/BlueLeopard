// 2021-2.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
using namespace std;

int i=100;
void fun(){
    static int i=1;
    i++;
    cout << i;
}

int main(){
    fun();
    cout << i;
    return 0;
}

