// BCT2021-2.cpp
// Created by 蓝同学 on 2021/9/8.
// 将整型数n转换为字符串
#include <iostream>
using namespace std;

char *itos (int n){
    char *s = new char[12]; // 2^32-1有10位，且可能是负数，再加上'\0'
    int i=0, scale = 1000000000; // scale的解释如上

    if (n == 0){ // 特殊情况0
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    if (n < 0){ // 处理负数
        s[0] = '-';
        n = -n;
        ++i;
    }

    // 最大规模是1000000000，实际上不一定是那么大的数
    // 从大到小确定正确的规模
    while ( n / scale == 0)
        scale /= 10;

    // 如果是个位数则scale=1
    while (scale > 0){
        s[i] = n / scale + '0';
        n %= scale;
        ++i;
        scale /= 10; // 如果scale=1, 那么就要结束了
    }

    s[i] = '\0';
    return s;
}


int main(){

    return 0;
}

