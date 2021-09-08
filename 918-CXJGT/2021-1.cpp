// 2021-1.cpp
// Created by 蓝同学 on 2021/9/7.
//

#include <iostream>
using namespace std;

class One{
public:
    virtual void f(){ cout << 1; }
};

class Two:public One{
public:
    Two(){ cout << 2; }
};

class Three:public Two{
public:
    virtual void f() {
        Three::f();
        cout << 3;
    }
};

int main(){
    One one;
    Two two;
    Three three;

    One *p;
//    p->f();
    return 0;
}

