#include <iostream>
using namespace std;

int main() {
    int a[2][4]={{1,2,3,4},{5,6,7,8}};
    int b[4] = {11,22,33,44};
    int *p[4], (*q)[4];
    q=a;
    cout << sizeof(q) << endl; // 64位系统指针变量是8个字节
    cout << sizeof(a) << endl; // 2*4*4=32
    cout << q << endl; // 0x7ff7bcfbc6d0 指针变量指向的地址，即存放数组对应的常量指针的地址
    cout << a << endl; // 0x7ff7bcfbc6d0 也就是数组的首地址
    cout << &q << endl; // 0x7ff7b19ed6a0 存放指针变量的地址
    cout << &a << endl; // 0x7ff7b19ed6d0 存放数组对应的常量指针的地址
    cout << a[0] << endl; // 0x7ff7bbcd76d0 二维数组，所以a[0]是第一行的首地址
    cout << q[0] << endl; // 0x7ff7bbcd76d0
    q=&b; // 一维数组对应一级指针（但不等价），二维数组对应二级指针（但不等价）
    cout << q << endl;
    cout << b << endl;





    return 0;
}
