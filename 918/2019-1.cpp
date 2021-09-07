// 2019-1.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
using namespace std;

int main(){
    int a=1, b=1;
    for(; a<=100; a++){
        if(b>=10)
            break;
        if(b%3==1){
            b+=3;
            continue;
        }
    }
    cout << a << endl;
    return 0;
}

/*
 * a=1,b=1
 * b=4,a=2
 * b=7,a=3
 * b=10,a=4
 * */

