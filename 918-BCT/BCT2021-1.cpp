// 2021-1.cpp
// Created by 蓝同学 on 2021/9/8.
// page70, 第4章，循环程序设计-枚举法
// ABCD*E = DCBA，求ABCDE这5个不同数字
// 特别注意，是5个不同的数字

#include <iostream>
using namespace std;

int main(){
    int num1, num2, A, B, C, D, E;
    for(num1 = 1023; num1 <= 9876; ++num1){
        A = num1 / 1000;
        B = (num1 % 1000) / 100;
        C = (num1 % 100) / 10;
        D = (num1 % 10) / 1;
        if(D==0 || A==B || A==C || A==D || B==C || B==D || C==D)
            continue;
        num2 = D*1000 + C*100 + B*10 + A;
        for(E = 2; E<=9; ++E){
            if(E==A || E==B || E==C || E==D)
                continue;
            if(num1*E == num2){
                cout << "ABCDE=" << num1 << E << endl;
            }
        }
    }
    return 0;
}

