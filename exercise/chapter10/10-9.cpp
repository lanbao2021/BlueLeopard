// 10-9.cpp
// Created by 蓝同学 on 2021/9/2.
//

#include <iostream>
#include <cstring>
using namespace std;

class dictionary{
private:
    struct item{
        char english[15];
        char chinese[20];
    };
    int size; // 最大可容纳词条数
    int curLen; // 当前词条数
    item *data;

    int find(int low, int high, char *word) const;
    void doubleSpace();

public:
    dictionary(int s):curLen(0), size(s){ data = new item[size]; }
    ~dictionary(){ delete [] data; }
    void insert(char *e, char *s);
    void remove(char *e);
    char *find(char *e) const;
    void print() const{
        for(int i=0; i<curLen; ++i)
            cout << data[i].english << '\t' << data[i].chinese << endl;
    }
};

char *dictionary::find(char *e) const {
    int pos;
    if(curLen == 0)
        return NULL;
    pos = find(0, curLen - 1, e);
    if(strcmp(e, data[pos].english) != 0)
        return NULL;
    return data[pos].chinese;
}

int dictionary::find(int low, int high, char *word) const{
    int mid, result;
    while(low < high){
        mid = (low + high) / 2;
        result = strcmp(word, data[mid].english); // strcmp(s1, s2)=0则s1=s2, 返回大于0的值则s1>s2，返回小于0的值则s1<s2
        if(result == 0)
            return mid;
        if(result > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (low + high) / 2 + 1; // 这里并不是很理解，暂时先记住吧
}


void dictionary::insert(char *e, char *s) {
    int pos;
    if(curLen == 0){
        strcpy(data[0].english,e);
        strcpy(data[0].chinese,s);
        ++curLen;
        return;
    }

    pos = find(0, curLen - 1, e);
    if(strcmp(e, data[pos].english) == 0){
        cout << "词条已存在！" << endl;
        return;
    }
    if(curLen == size)
        doubleSpace();
    for(int i=curLen; i>pos; --i) // 这是在干啥？空出pos对应的位置，pos后的空间往后挪一个身位
        data[i] = data[i-1];
    strcpy(data[pos].english, e);
    strcpy(data[pos].chinese, s);
    ++curLen;
}

void dictionary::doubleSpace() {
    item *tmp = data;
    size *= 2;
    data = new item[size];
    for(int i=0; i<curLen; ++i)
        data[i] = tmp[i];
    delete [] tmp; // 删除动态数组，参考答案里不规范
}


void dictionary::remove(char *e) {
    int pos;
    if(curLen == 0){
        cout << "词条不存在！" << endl;
        return;
    }

    pos = find(0, curLen - 1, e);
    if(strcmp(e, data[pos].english) != 0){
        cout << "词条不存在" << endl;
        return;
    }
    for(int i=pos; i<curLen-1; ++i) // pos要删除，通过让pos后面的数直接覆盖pos，一个一个往前挪
        data[i] = data[i+1];
    --curLen; //词条数减1
}
int main(){
    return 0;
}