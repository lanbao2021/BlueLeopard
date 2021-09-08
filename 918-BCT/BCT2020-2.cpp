// BCT2020-2.cpp
// Created by 蓝同学 on 2021/9/8.
// 一个支持整型、实型和字符型的气泡排序的函数模板
#include <iostream>
using namespace std;

template<class T>
void bubbleSort(T data[], int size){
    int i, j;
    bool flag;
    T tmp;

    for(i=1; i<size; ++i){ // 完成size-1次气泡
        flag = false;
        for(j=0; j<size-1; ++j){
            if(data[j] > data[j+1]){
                tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                flag = true; // 有发生交换
            }
        }
        if(!flag)
            break; // 没有发生交换，已排好序，结束
    }
}

int main(){
    return 0;
}

