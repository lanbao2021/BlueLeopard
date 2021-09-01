// 10-2.cpp
// Created by 蓝同学 on 2021/9/1.
//
#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt{
private:
    char *num;
public:
    LongLongInt(const char *n="");
    LongLongInt(const LongLongInt &);
    ~LongLongInt() {delete num;}
    void print() const;
    void add(const LongLongInt &, const LongLongInt &);
    void assign(const LongLongInt &);
    bool equal(const LongLongInt &) const;
    bool greater(const LongLongInt &) const;
    bool greaterOrEqual(const LongLongInt &) const;
};

LongLongInt::LongLongInt(const char *n) {
    int len = strlen(n);
    num = new char[len + 1];
    for(int i=0; i < len; ++i)
        num[len-i-1] = n[i];
    num[len] = '\0';
}

LongLongInt::LongLongInt(const LongLongInt &other) {
    num = new char[strlen(other.num) + 1];
    strcpy(num, other.num);
}

void LongLongInt::print() const {
    for (int i = strlen(num); i >= 0; --i)
        cout << num[i];
    if (strlen(num) == 0)
        cout << 0;
}
void LongLongInt::add(const LongLongInt &n1, const LongLongInt &n2) {
    int len1 = strlen(n1.num), len2 = strlen(n2.num);
    int minLen = (len1 > len2 ? len2 : len1);
    int len = (len1 > len2 ? len1 : len2) + 1;
    int carry = 0, result;                             // carry:进位
    num = new char[len + 1];
    int i;
    for (i = 0; i < minLen; ++i) {
        result = n1.num[i] - '0' + n2.num[i] - '0' + carry;
        num[i] = result % 10 + '0';
        carry = result / 10;
    }
    while (i < len1) {                                 // n2已结束
        result = n1.num[i] - '0' + carry;
        num[i] = result % 10 + '0';
        carry = result / 10;
        ++i;
    }
    while (i < len2) {                                  // n1已结束
        result = n2.num[i] - '0' + carry;
        num[i] = result % 10 + '0';
        carry = result / 10;
        ++i;
    }
    if(carry != 0)  // 处理最高位的进位
        num[i++] = carry + '0';
    num[i] = '\0';

    if(i != len){
        char *tmp = num;
        num = new char[len];
        strcpy(num, tmp);
        delete tmp;
    }
}

int main(){
    LongLongInt n1("123");
    LongLongInt n2("1423");
    LongLongInt n;
    n.add(n1, n2);
    n.print();
    cout << '\0' << endl;
    return 0;
}