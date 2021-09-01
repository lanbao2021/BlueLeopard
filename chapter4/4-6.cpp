// 4-6.cpp
// Created by 蓝同学 on 2021/8/8.
// n层倒三角星星堆
#include <iostream>
using namespace std;
int main(){
    int N;
    cout << "input:";
    cin >> N;
    for(int i=1; i<=N; i++){
        int space = N-i;
        for(; space; space--)
            cout << " ";
        int star = 2*i - 1;
        for(; star; star--)
            cout << "*";
        cout << endl;
    }
    return 0;
}

