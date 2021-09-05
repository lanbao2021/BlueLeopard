// 11-3.cpp
// Created by 蓝同学 on 2021/9/5.
//
#include <iostream>
using namespace std;

class Vector{
    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);
    friend Vector operator+(const Vector &, const Vector &);
    friend double operator*(const Vector &, const Vector &);

private:
    double data[10];
public:
    Vector(double *dat = NULL);
};

Vector::Vector(double *dat) {
    if(dat != NULL)
        for(int i=0; i<10; ++i)
            data[i] = dat[i];
        else
            for(int i=0; i<10; ++i)
                data[i]=0;
}

ostream &operator<<(ostream &os, const Vector &obj){
    os << "(" << obj.data[0] ;
    for(int i=1; i<10; ++i)
        os << "," << obj.data[i];
    os << ")" ;
    return os;
}

istream &operator>>(istream &is, Vector &obj){
    for(int i=0; i<10; ++i)
        is >> obj.data[i];
    return is;
}

Vector operator+(const Vector &v1, const Vector &v2){
    Vector result(v1);
    for(int i=0; i<10; ++i)
        result.data[i] += v2.data[i];
    return result;
}

double operator*(const Vector &v1, const Vector &v2){
    double result = 0;
    for(int i=0; i<10; ++i)
        result += v1.data[i]*v2.data[i];
    return result;
}

int main(){
    return 0;
}