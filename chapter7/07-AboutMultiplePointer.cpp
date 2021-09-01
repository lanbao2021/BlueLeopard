// 07-About Multiple Pointer.cpp
// Created by 蓝同学 on 2021/8/15.
// 对多级指针的理解
#include<iostream>
static int s_num=10;
void fun(int** q){
    std::cout << &q << std::endl; // 0x10d1b6778 二级指针变量q的地址
    std::cout << q << std::endl; // 0x10d1b6790 二级指针变量q指向的地址（正是p的地址）
    std::cout << *q << std::endl; // 0x10d1b6798 访问二级指针变量q指向的地址（正是p指向的地址，即num的地址）
    std::cout << **q << std::endl; // 5 访问二级指针变量q指向地址指向的地址（正是p指向的地址，即num的地址，即访问num的值）
    *q = &s_num; // p指向的地址变为s_num的地址
}

void fun(int* &p){
    std::cout << *p << std::endl;
    p = &s_num;
}


int main(){
    int num=5;
    int *p = &num;
    std::cout << &p << std::endl; // 0x10d1b6790 指针变量的地址
    std::cout << p << std::endl; // 0x10d1b6798 指针变量指向的地址（指向=保存）
    std::cout << *p << std::endl; // 5 访问指针变量指向的地址（指向=保存）
    fun(&p); // 传入指针变量的地址
    std::cout << p << std::endl; // 0x108378048 此时p指向了s_num的地址（指向=保存）
    std::cout << *p << std::endl; // 10 访问p指向的地址，输出s_num的值
    p = &num;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    fun(p);
    std::cout << p << std::endl;
    std::cout << *p << std::endl;
    return 0;
}



