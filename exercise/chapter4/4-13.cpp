// 4-13.cpp
// Created by 蓝同学 on 2021/8/15.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int num, guess;
    srand(time(NULL));
    num = rand() % (100+1);
    for(int i=0;i<10;++i){
        cout << "请输入你的预测：";
        cin >> guess;
        if(guess==num)
            break;
        else if(guess<num)
            cout << "too small" << endl;
        else
            cout << "too big" << endl;
    }
    if(guess==num)
        cout << "You win." << endl;
    else
        cout << "You failed." << endl;
    return 0;
}


