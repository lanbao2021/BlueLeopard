// 2021-1.cpp
// Created by 蓝同学 on 2021/9/8.
// page70, 第4章，循环程序设计-枚举法
// ABCD*E = DCBA，求ABCDE这5个不同数字
// 特别注意，是5个不同的数字
/*
1. 想清楚ABCD的取值范围，想清楚E的取值范围
2. 如何通过ABCD得到A，B，C，D呢？比如1234要得到1，2，3，4
3. D能否为零？A、B、C、D之间能否相等？
4. 如何通过A，B，C，D得到DCBA?
5. 想清楚为什么E≠1
6. E能否和A、B、C、D中的任意一个数字相等？
*/
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

