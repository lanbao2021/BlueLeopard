// 4-8.cpp
// Created by 蓝同学 on 2021/8/8.
//
#include <iostream>
using namespace std;
int main(){
    int n, sum;
    sum = n = 1;
    for(int i=2; i<=10; i++){
        n *= i;
        sum += n;
    }
    cout << sum << endl;
    return 0;
}
