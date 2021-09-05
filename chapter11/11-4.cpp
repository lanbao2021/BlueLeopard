// 11-4.cpp
// Created by 蓝同学 on 2021/9/5.
//
#include <iostream>
using namespace std;

class String{
    friend  String operator+(const String &s1, const String &s2);
    friend ostream &operator<<(ostream &os, const String &obj);
    friend istream &operator>>(istream &is, String &obj);
    friend bool operator>(const String &s1, const String &s2);
    friend bool operator>=(const String &s1, const String &s2);
    friend bool operator==(const String &s1, const String &s2);
    friend bool operator!=(const String &s1, const String &s2);
    friend bool operator<(const String &s1, const String &s2);
    friend bool operator<=(const String &s1, const String &s2);

private:
    int len;
    char *data;
    String(const char *s = "");
    String(const String &other);
    String &operator+=(const String &other);
    String &operator=(const String &other);
    String operator()(int start, int end);
    char &operator[](int index) { return data[index]; }
    ~String() { delete data; }
};

String::String(const char *s) {
    for(len=0; s[len] !=0; ++len); // 判断字符串s的长度
    data = new char[len + 1];
    for(int i=0; i<len; ++i)
        data[i] = s[i];
    data[len] = '\0';
}

String::String(const String &s){
    len = s.len;
    data = new char[len+1];
    for(int i=0; i<len; ++i)
        data[i] = s.data[i];
    data[len] = '\0';
}

String &String::operator=(const String &other) {
    if(this == &other)
        return *this;
    delete data;
    len = other.len;
    data = new char[len + 1];
    for(int i=0; i<len; ++i)
        data[i] = other.data[i];
    data[len] = '\0';
    return *this;
}

bool operator>(const String &s1, const String &s2){
    for (int i=0; i<s1.len; ++i){
        if (s1.data[i] > s2.data[i])
            return true;
        if (s1.data[i] < s2.data[i])
            return false;
    }
    return false;
}

bool operator>=(const String &s1, const String &s2){
    for (int i=0; i<s1.len; ++i){
        if (s1.data[i] > s2.data[i])
            return true;
        if (s1.data[i] < s2.data[i])
            return false;
    }
    return true;
}

bool operator==(const String &s1, const String &s2){
    if(s1.len != s2.len)
        return false;
    for(int i=0; i<s1.len; ++i)
        if(s1.data[i] != s2.data[i])
            return false;
    return true;
}

bool operator!=(const String &s1, const String &s2){ return !(s1 == s2); }
bool operator<(const String &s1, const String &s2){ return !(s1 >= s2); }
bool operator<=(const String &s1, const String &s2){ return !(s1 > s2); }

//字符串的连接
String &String::operator+=(const String &other){
    char *tmp=data;
    int i;

    data = new char[len + other.len + 1];
    for(i=0; i<len; ++i)
        data[i] = tmp[i];
    for(i=0; i<other.len; ++i)
        data[len + i] = other.data[i];
    len += other.len;
    data[len] = '\0';
    return *this;
}

String operator+(const String &s1, const String &s2){
    String tmp(s1);
    tmp += s2;
    return tmp;
}

//取子串的功能用函数调用运算符重载来实现
String String::operator()(int start, int end) {
    if(start > end || start < 0 || end >= len)
        return String("");

    String tmp;
    delete tmp.data;
    tmp.len = end - start + 1;
    tmp.data = new char[tmp.len + 1]; // tmp.len这边参考答案有误
    int i;
    for(i=0; i<= end - start; ++i)
        tmp.data[i] = data[i + start];
    tmp.data[i] = '\0';
    return tmp;
}

// 输出重载比较容易
ostream &operator<<(ostream &os, const String &obj){
    os << obj.data;
    return os;
}

// 输入重载有些麻烦，因为我们不知道用户输入的字符串有多长，无法为data申请合适的空间
// 所以输入重载采用了一个块状链表作为过渡
istream  &operator>>(istream &is, String &obj){
    struct Node{    // 块状链表的结点类
        char ch[10];
        Node *next;
    };

    Node *head, *tail, *p; // 块状链表的头指针、尾指针
    int len=0, i;

    head = tail = new Node;
    while( (tail->ch[len % 10] = is.get()) != '\n'){
        ++len;
        if(len % 10 == 0){  // 存入10个字符后申请一个新结点
            tail->next = new Node;
            tail = tail->next;
        }
    }

    obj.len = len;
    delete obj.data;
    obj.data = new char[len + 1];
    for(i=0; i<len; ++i){
        obj.data[i] = head->ch[i % 10];
        if(i % 10 == 9){ // 读取10个字符后换下一个结点
            p = head;
            head = head->next;
            delete p;
        }
    }

    delete head;
    obj.data[len] = '\0';
    return is;
}


int main(){
    return 0;
}

