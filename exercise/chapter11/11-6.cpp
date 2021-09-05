// 11-6.cpp
// Created by 蓝同学 on 2021/9/5.
//
#include <iostream>
#include <cstring>
using namespace std;

class boolean{
    friend ostream &operator<<(ostream &os, const boolean &obj);
    friend istream &operator>>(istream &is, boolean &obj);

private:
    bool data;
public:
    boolean(bool d=false):data(d) {}
    boolean(const char *s) { data = (strcmp(s, "true") == 0 ? true : false); }
    operator int() const { return (data ? 1 : 0); } //  类类型到其他类型的转换page268
};

ostream &operator<<(ostream &os, const boolean &obj){
    os << (obj.data ? "true" : "false") ;
    return os;
}

istream &operator>>(istream &is, boolean &obj){
    char tmp[6];
    is >> tmp;
    obj.data = (strcmp(tmp, "true") == 0 ? true : false);
    return is;
}

int main(){
    return 0;
}

