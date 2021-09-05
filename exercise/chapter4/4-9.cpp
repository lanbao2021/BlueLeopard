// 4-9.cpp
// Created by 蓝同学 on 2021/8/8.
// 求1 – 2 + 3 – 4 + 5 – 6 + …… +/- N的值
#include <iostream>
using namespace std;
int main(){
    int N;
    cout << "input:";
    cin >> N;
    int sum = 0;
    for(int i=1; i<=N; i++){
        if(i%2)
            sum += i;
        else
            sum -= i;
    }
    cout << sum << endl;
    return 0;
}

