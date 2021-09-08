// 2019-2.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {1,2,3,
                     4,5,6,
                     7,8,9};
    for(int k=0; k<3; k++){
        cout << arr[k][2-k] << " ";
    }
    return 0;
}

//k=0, arr[0][2],3
//k=1, arr[1][1],5
//k=2, arr[2][0],7

