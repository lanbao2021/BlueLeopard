// 6-21.cpp
// Created by 蓝同学 on 2021/8/17.
//
#include <iostream>
using namespace std;

void print(double d);
void printFix(double d);
void printInt(int n);
void printFloat(double d);

int main(){
//    double d = .0000000016;
    double d = 1123431.1213143;
//    int digit;
//    cout << d - int(d) << endl;
//    digit = d *= 10;
//    cout << digit << ' ' << d << ' ' << d - digit;
    print(d);
    return 0;
}
void print(double d){
    if(d < 0){
        cout << "-";
        d = -d;
    }
    if(d > 1e8 || d < 1e-8)
        printFloat(d);
    else
        printFix(d);
}

void printFix(double d){
    int scale = 1, digit;
    int len = 0;
    double epsilon = 1e-8;
    printInt(d);

    if(d - int(d) < 1e-8) return; // d without small digits part

    // get the length of integral part
    while(scale < d){
        scale *= 10;
        ++len;
        epsilon *= 10; // what's the function?
    }
    scale /= 10; // 要除以个10

    cout << ".";

    d -= int(d);

    // print the small digits part
    while(len < 7 && d > epsilon){
        digit = d *= 10;
        cout << char(digit + '0');
        d -= digit;
        ++len;
        epsilon *= 10; // what's the function?
    }

    if(d > 1e-8){
        digit = d *= 10;
        if(d - digit > 0.5)
            ++digit;
        cout << char(digit + '0');
    }
}
void printFloat(double d){
    int len = 0;
    if(d > 1)
        while(d > 10) {
            d /= 10;
            ++len;
        }
    else
        while(d < 1){
            d *= 10;
            --len;
        }
    printFix(d);
    cout << 'e';
    printInt(len);

}
void printInt(int n){
    if(n < 0){
        cout << '-';
        n = -n;
    }
    if(n < 10)
        cout << char(n + '0');
    else{
        printInt(n/10);
        cout << char(n % 10 + '0');
    }

}
