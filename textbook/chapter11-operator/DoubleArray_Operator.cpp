// DoubleArray_Operator.cpp
// Created by 蓝同学 on 2021/9/3.
//
#include "DoubleArray_Operator.h"
#include <cassert>

DoubleArray::DoubleArray(const DoubleArray &arr) {
    low = arr.low;
    high = arr.high;
    storage = new double[high - low + 1];
    for(int i=0; i<(high-low); ++i)
        storage[i] = arr.storage[i];
}

DoubleArray &DoubleArray::operator=(const DoubleArray &right) {
    if(this == &right)
        return *this; // 防止自己复制自己
    delete [] storage;

    low = right.low;
    high = right.high;
    storage = new double[high - low + 1];
    for(int i=0; i<= high - low; ++i)
        storage[i] = right.storage[i];
    return *this;
}


double &DoubleArray::operator[](int index){
    // assert函数需要头文件<cassert>
    assert(index >= low && index <= high);
    return storage[index - low];
}

const double &DoubleArray::operator[](int index) const{
    assert(index >= low && index <= high);
    return storage[index - low];
}

ostream &operator<<(ostream &os, const DoubleArray &obj){
    os << "数组内容为：\n" ;
    for(int i=obj.low; i<=obj.high; ++i)
        os << obj[i] << '\t';
    os << endl;
    return os;
}

istream &operator>>(istream &is, DoubleArray &obj){
    cout << "请输入数组元素[" << obj.low << "," << obj.high << "]:\n";
    for(int i=obj.low; i<=obj.high; ++i)
        is >> obj[i];
    return is;
}

bool operator==(const DoubleArray &obj1, const DoubleArray &obj2){
    if(obj1.low != obj2.low || obj1.high != obj2.high)
        return false;
    for(int i=obj1.low; i<obj1.high; ++i)
        if(obj1[i] != obj2[i])
            return false;
    return true;
}

DoubleArray DoubleArray::operator()(int start, int end, int lh){
    assert(start <= end && start >= low && end <= high);
    DoubleArray tmp(lh, lh + end - start);
    for(int i=0; i<end-start+1; ++i)
        tmp.storage[i] = storage[start + i - low];
    return tmp;
}