// 2019-3.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[20];
    cin >> str;
    int k=strlen(str);
    for(int i=0; i<k; i++)
        cout << str[k-i-1];
    return 0;
}

//abcdefg

//i=0,k=7,str[7-0-1]=str[6]=g;
//i=1,k=7,str[7-1-1]=str[5]=f;
//i=2,k=7,str[7-2-1]=str[4]=e;
//i=3,k=7,str[7-3-1]=str[3]=d;
//i=4,k=7,str[7-4-1]=str[2]=c;
//i=5,k=7,str[7-5-1]=str[1]=b;
//i=6,k=7,str[7-6-1]=str[0]=a;



