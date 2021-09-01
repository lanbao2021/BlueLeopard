// 10-3.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt{
private:
    struct Node{
        char data;
        Node *next;
        // 结构体内元素的初始化也可以有构造函数，初始化列表
        Node(char c=' ', Node *n = NULL):data(c), next(n){}
    };
    Node *num;

    //工具函数
    void remove();
    void copy(const LongLongInt &other);
    void print(Node *p) const;
    int compare(const Node *n1, const Node *n2) const;
public:
    LongLongInt(const char *n="");
    LongLongInt(const LongLongInt &);
    void print() const;
    void add(const LongLongInt &, const LongLongInt &);
    void assign(const LongLongInt &);
    bool equal(const LongLongInt &) const;
    bool greater(const LongLongInt &) const;
    bool greaterOrEqual(const LongLongInt &) const;
    ~LongLongInt();
};

LongLongInt::LongLongInt(const char *n){
    num = new Node;
    while(*n){
        num->next = new Node(*n, num->next);
        ++n;
    }
}

LongLongInt::LongLongInt(const LongLongInt &other){
    num = new Node;
    copy(other);
}

void LongLongInt::copy(const LongLongInt &other){
    Node *p = other.num->next, *tail = num;
    while(p != NULL){
        tail->next = new Node(p->data);
        tail = tail->next;
        p = p->next;
    }
}

void LongLongInt::print() const {
    if(num->next == NULL)
        cout << 0;
    else
        print(num->next); // 注意这里是函数重载
}

void LongLongInt::print(Node *p) const {
    if(p != NULL){
        print(p->next);
        cout << p->data;
    }
}

void LongLongInt::remove() {
    Node *p = num->next, *q;
    num->next = NULL;
    while (p !=NULL){
        q = p->next;
        delete p;
        p = q;
    }
}

void LongLongInt::add(const LongLongInt &n1, const LongLongInt &n2) {
    Node *num1 = n1.num->next, *num2 = n2.num->next, *tail, *tmp;
    int carry = 0, result;

    remove(); // 先清空自己
    tail = num;
    while(num1 != NULL && num2 != NULL){
        result = num1->data - '0' + num2->data - '0' + carry;
        tail->next = new Node(result % 10 + '0');
        tail = tail->next;
        carry = result / 10;
        num1 = num1->next;
        num2 = num2->next;
    }
    tmp = (num1 ? num1 : num2);
    while(tmp != NULL){
        result = tmp->data - '0' + carry;
        tail->next = new Node(result % 10 + '0');
        tail = tail->next;
        carry = result / 10;
        tmp = tmp->next;
    }
    // 最后有进位
    if(carry != 0)
        tail->next = new Node(carry + '0');
}

// 赋值操作
void LongLongInt::assign(const LongLongInt &right) {
    if(this == &right)
        return;
    remove();
    copy(right);
}










int main(){
    return 0;
}

