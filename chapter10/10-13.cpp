// 10-13.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random{
public:
    Random() { srand(time(NULL)); }
    int RandomInt(int low, int high){ return (low + (high - low + 1) * rand() / (RAND_MAX + 1)); }
    double RandomDouble(double low, double high){ return low + (high - low + 1)*(double)rand() / (RAND_MAX + 1); }
    // 随机数的生成解析看README.md
};

int main(){
    return 0;
}

