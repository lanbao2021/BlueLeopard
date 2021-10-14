// problem_1.cpp
// Created by 蓝同学 on 2021/10/14.
// 若有定义 int a[4][5], (*ps)[5]=s, 则对s数组元素的正确引用是（ C ）
// A. ps + 1
// B. *(ps + 3)
// C. ps[0][2]
// D. *(ps+1) + 3
#include<iostream>
using namespace std;

void fun(){
    int s[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    int (*ps)[5]=s;
    cout << ps + 1 << endl;
    cout << *(ps + 3) << endl;
    cout << ps[0][2] << endl;
    cout << *(ps + 1) + 3 << endl;
}

int main(){
    // 这题考察了：二维数组和数组指针

    // 如果是一维数组int a[5]，只需定义指针变量int *p=a;即可让p具有a的全部功能
    // 但注意：指针≠数组（后者是指针常量，占用的空间大小也不一致）
    // p占用的空间是8字节（64位系统），a占用的空间是4*5*4=80字节

    // 如果是二维数组int a[4][5]，则需定义数组指针变量int (*p)[5]=a;才能使p具有a的全部功能
    // 类似一维数组不能认为p等价于a

    // 定义二维数组a
    int a[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    // 定义数组指针p
    int (*p)[5]=a;

    // p = a = *p = *a = p[0] = a[0]
    cout << "p = a = *p = *a = p[0] = a[0]" << endl;
    cout << p << endl;
    cout << a << endl;
    cout << *p << endl;
    cout << *a << endl;
    cout << p[0] << endl;
    cout << a[0] << endl;

    // **p = **a = *p[0]= *a[0] = p[0][0]= a[0][0]
    cout << "**p = **a = *p[0]= *a[0] = p[0][0]= a[0][0]" << endl;
    cout << **p << endl;
    cout << **a << endl;
    cout << *p[0] << endl;
    cout << *a[0] << endl;
    cout << p[0][0] << endl;
    cout << a[0][0] << endl;

    // &p≠&a, sizeof(p)≠sizeof(a)
    cout << &p << endl;
    cout << &a << endl;
    cout << sizeof(p) << endl; // 8（64位系统）
    cout << sizeof(a) << endl; // 80

    return 0;
}

