// 16-1.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
#include <cstring>
using namespace std;

template<class T>
class seqList{
private:
    int size; // 数组规模
    int current_size; // 容器中对象的个数
    T *storage; // 数组的起始地址
    void doubleSpace(); // 将数组容量扩大一倍
public:
    seqList(int s=0):size(s){ storage = new T[size]; current_size=0; }
    ~seqList() { delete [] storage; }

    // 在容器尾部添加对象
    void push_back(const T &x){
        if(size == current_size)
            doubleSpace();
        storage[current_size++] = x;
    }

    // 删除容器尾部的对象
    void pop_back(){
        if(current_size == 0)
            cerr << "This is a empty Vector" << endl;
        else
            --current_size;
    }

    // 下标运算符重载
    T &operator[](int i){ return storage[i]; }

    // 迭代器类的定义
    class Itr{
        T *pos; // 指向容器中的某一个对象
    public:
        Itr(T *obj = NULL){ pos = obj; }
        Itr &operator++() { ++pos; return *this; } // 指向容器中的下一对象
        T &operator*() { return *pos; } // 取迭代器指向的对象值
        bool operator !=(const Itr &p) { return pos != p.pos; } // 比较两迭代器对象是否相同

        friend class seqList<T>;
    };

    Itr begin() { return Itr(storage); } // 返回指向第一个对象的迭代器
    Itr end() { return Itr(storage + current_size); } // 返回指向最后一个对象的迭代器
    void insert(Itr &p, const T &x); // 在迭代器指定的位置上插入对象
    void erase(const Itr &p); // 删除迭代器指定位置上的对象
};

template<class T>
void seqList<T>::doubleSpace() {
    T *tmp = storage;
    size *= 2;
    storage = new T[size];
    for(int i=0; i<current_size; ++i)
        storage[i] = tmp[i];
    delete [] tmp;
}

template<class T>
void seqList<T>::insert(Itr &p, const T &x){
    T *q;
    if(size == current_size){
        int offset = p.pos - storage;
        doubleSpace();
        p.pos = storage + offset; // 扩大空间位置后storage的地址空间改变，重新赋值给pos
    }
    q = storage + current_size;
    while(q > p.pos){
        // 迭代器指出的对象后的所有对象后移一个位置
        *q = *(q-1);
        --q;
    }
    *p.pos = x;
    ++current_size;
}

template<class T>
void seqList<T>::erase(const Itr &p){
    T *q = p.pos;
    --current_size;
    while(q < storage + current_size){
        *q = *(q + 1);
        ++q;
    }
}

int main(){

    // 定义一个存放整型对象的顺序容器，初始容量为10个对象
    seqList<int> sq(10);

    // 定义一个对应的迭代器类的对象
    seqList<int>::Itr itr1;

    for(int i=0; i<10; ++i)
        sq.push_back(2*i + 1);

    cout << "用下标运算符输出：\n";
    for(int i=0; i<10; ++i)
        cout << sq[i] << '\t';

    cout << "\n用迭代器输出：\n";
    for(itr1 = sq.begin(); itr1 != sq.end(); ++itr1)
        cout << *itr1 << '\t';

    // 插入0，2，4，6，8，10，12，14，16，18
    int i;
    for(itr1 = sq.begin(), i=0; i<20; ++itr1, ++itr1, i += 2)
        sq.insert(itr1, i);
    cout << "\n插入0，2，4，6，8，10，12，14，16，18后：\n";
    for(itr1 = sq.begin(); itr1 != sq.end(); ++itr1)
        cout << *itr1 << '\t';

    // 删除0，2，4，6，8，10，12，14，16，18
    for(itr1 = sq.begin(); itr1 != sq.end(); ++itr1)
        sq.erase(itr1);
    cout << "\n删除0，2，4，6，8，10，12，14，16，18后：\n";
    for(itr1 = sq.begin(); itr1 != sq.end(); ++itr1)
        cout << *itr1 << '\t';

    return 0;
}
