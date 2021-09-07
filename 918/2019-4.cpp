// 2019-4.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
using namespace std;

class A{
    static int n;
public:
    A(){ n+=2; }
    ~A(){ n-=3; }
    int getN(){
        return n;
    }
};

int A::n=1;

int main(){
    A *a = new A(); // 执行构造函数，n=3
    delete a; // 执行析构函数，n=0
    cout << a << endl;
    cout << "n=" << a->getN() << endl; // 为啥这个a还能访问？？？？？？？？？？
    cout << a;
    return 0;
}
