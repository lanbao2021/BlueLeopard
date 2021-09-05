// 4-4.cpp
// Created by 蓝同学 on 2021/8/8.
// 写一个程序,提示用户输入一个正整数,然后输出这个整型数的每一位数字,数字之间插一个空格。例如当输入是12345时,输出为:1 2 3 4 5
#include <iostream>
using namespace std;
int main(){

    int n, i;
    cout << "input：" ;
    cin >> n;
    for(i = 10; n>=i; i*=10); // 计算n的数量级，如101的数量级为100
    i /= 10; // 前面for循环计算的是1000，多了一倍
    while(i>0){
        cout << n/i << " ";
        n %= i;
        i /= 10;
    }

    return 0;
}

