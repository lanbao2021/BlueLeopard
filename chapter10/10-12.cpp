// 10-12.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
using namespace std;

class List{
private:
    int size;
    int curLen;
    int *data;

    int find(int key, int nil) const; // nil参数是凑数的
    void doubleSpace();
public:
    List(int s):curLen(0), size(s){ data = new int[size]; }
    ~List() { delete [] data; }
    void insert(int key);
    void remove(int key);
    int find(int n) const{
        if(n > curLen || n <= 0)
            return -1;
        else
            return data[n-1];
    }
    void print() const{
        for(int i=0; i<curLen; ++i)
            cout << data[i] << '\t';
        cout << endl;
    }
};

void List::remove(int key) {
    int pos;
    if(curLen == 0){
        cout << "数值不存在！" << endl;
        return;
    }

    pos = find(key, 0); // 有两个find，这个是用于插入删除
    if(data[pos] != key){
        cout << "数值不存在" << endl;
        return;
    }

    for(int i=pos; i<curLen-1; ++i) // 后面的元素往前挪一挪
        data[i] = data[i+1];
    --curLen;
}

int List::find(int key, int nil) const {
    int mid, low = 0, high = curLen - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(data[mid] == key)
            return mid;
        if(key > data[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (low + high) / 2 + 1; // 记住结论，按顺序插入时是这个位置
}

void List::doubleSpace() {
    int *tmp = data;
    size *= 2;
    data = new int[size];
    for(int i=0; i<curLen; ++i)
        data[i] = tmp[i];
    delete [] tmp;
}

void  List::insert(int key) {
    int pos;
    if(curLen == 0){
        data[curLen++] = key;
        return;
    }
    pos = find(key, 0);
    if(key == data[pos]){
        cout << "数值已存在！" << endl;
        return;
    }

    if(curLen == size)
        doubleSpace();
    for(int i=curLen; i>pos; --i)
        data[i] = data[i-1];
    data[pos] = key;
    ++curLen;
}

int main(){
    return 0;
}

