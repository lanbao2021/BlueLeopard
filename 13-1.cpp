// 13-1.cpp
// Created by 蓝同学 on 2021/9/6.
// 类模板的定义、实现、实例化
#include <iostream>
using namespace std;

template <class T>
class Array{
    int low;
    int high;
    T *storage;
public:
    // 构造函数
    Array(int lh=0, int rh=0):low(lh), high(rh){
        storage = new T[high-low+1];
    }

    // 复制构造函数
    Array(const Array &arr);

    // 赋值运算符重载函数
    Array &operator=(const Array &a);

    // 下标运算符重载函数
    T &operator[](int index);

    // 析构函数
    ~Array() {
        if(storage)
            delete [] storage;
    }
};


// 类模板Array的成员函数实现
// 复制构造函数
template <class T>
Array<T>::Array(const Array<T> &arr){
    low = arr.low;
    high = arr.high;
    storage = new T[high-low+1];
    for(int i=0; i<high-low+1; ++i)
        storage[i] = arr.storage[i];
}

// 赋值运算符重载函数
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if(this == &other)
        return *this;
    delete [] storage;
    low = other.low;
    high = other.high;
    storage = new T[high-low+1];
    for(int i=0; i<=high-low+1; ++i)
        storage[i] = other.storage[i];
    return *this;
}

// 下标运算符重载函数
template <class T>
T & Array<T>::operator[](int index){
    if(index<low || index>high){
        cout << "下标越界！" ;
        exit(-1);
    }
    return storage[index-low];
}

int main(){
    // 类模板的实例化
    Array<int> array1(20, 30);
    for(int i=20; i<=30; ++i)
        cout << array1[i] << '\t';
    return 0;
}
