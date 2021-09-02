// 10-5.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
using namespace std;

class String{
private:
    int len;
    char *data;
public:
    String(const char *s = "");
    String(const String &s);
    void Copy(const String &src);
    void Cat(const String &src);
    int Len() const{ return len; }
    void Print() const { cout << data; }
    ~String() { delete data; }
};

String::String(const char *s) {
    for(len = 0; s[len] != '\0'; ++len);
    data = new char[len + 1];
    for(int i=0; i<len; ++i)
        data[i] = s[i];
    data[len] = '\0';
}

String::String(const String &s){
    len = s.len;
    data = new char[len + 1];
    for(int i=0; i<len; ++i)
        data[i] = s.data[i];
    data[len] = '\0';
}

void String::Copy(const String &src) {
    delete [] data; //在CLion里面delete [] data和delete data都不会报错
    len = src.len;
    data = new char[len + 1];
    for(int i=0; i<len; ++i)
        data[i] = src.data[i];
    data[len] = '\0';
}

void String::Cat(const String &s){
    char *tmp = data;
    int i;
    data = new char[len + s.len + 1];
    for(i=0; i<len; ++i)
        data[i] = tmp[i];
    for(i=0; i<s.len; ++i)
        data[len + i] = s.data[i];
    len += s.len;
    data[len] = '\0';
}


int main(){
    String s1("1");
    String s2;
    s2.Copy(s1);
    s2.Print();
    return 0;
}

