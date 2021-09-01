// 4-2.cpp
// Created by 蓝同学 on 2021/8/8.
// 编写这样一个程序:先读入一个正整数N,然后计算并显示前N个奇数的和。例如,如果N为4,这个程序应显示16,它是1+3+5+7的和。
#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "输入N：";
    cin >> N;
    int out=0;
    for(int i=0; i<N; i++){
        out += 2*i + 1;
    }
    cout << out << endl;
    return 0;
}

