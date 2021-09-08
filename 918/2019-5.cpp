// 2019-5.cpp
// Created by 蓝同学 on 2021/9/8.
//
#include <iostream>
using namespace std;

class Base{
public:
    ~Base(){ cout << "BASE" << endl; }
};

class Derived:public Base{
public:
    ~Derived(){ cout << "DERIVED" << endl; }
};

int main(){
    Derived d;
    return 0;
}

