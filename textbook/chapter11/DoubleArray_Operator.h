// DoubleArray.h
// Created by 蓝同学 on 2021/9/3.
//

#ifndef BLUELEOPARD_DOUBLEARRAY_H
#define BLUELEOPARD_DOUBLEARRAY_H

#include <iostream>
using namespace std;

class DoubleArray{
    friend ostream &operator<<(ostream &os, const DoubleArray &obj);
    friend istream &operator>>(istream &is, DoubleArray &obj);
    friend bool operator==(const DoubleArray &obj1, const DoubleArray &obj2);

private:
    int low;
    int high;
    double *storage;
public:
    // 根据low和high为数组分配空间
    DoubleArray(int lh=0, int rh=0):low(lh), high(rh){ storage = new double[high - low + 1]; }

    // 复制构造函数
    DoubleArray(const DoubleArray &arr);

    //赋值运算符重载
    DoubleArray &operator=(const DoubleArray &right);

    // 下标运算符重载：作为左值/右值
    double &operator[](int index); // 左值
    const double &operator[](int index) const; // 右值

    // 取数组的一部分形成一个新的数组
    DoubleArray operator()(int start, int end, int lh);

    // 析构函数
    ~DoubleArray() { if(storage) delete [] storage; }

};

#endif //BLUELEOPARD_DOUBLEARRAY_H
