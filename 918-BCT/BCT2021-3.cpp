// BCT2021-3.cpp
// Created by 蓝同学 on 2021/9/8.
// 定义复数类CComplex，定义包含两个参数（其中一个有默认值）的构造函数
// 定义show()函数展示复数值
// 重载运算符+实现两个复数相加（重载为成员函数，不是友元全局函数）
// 编写主程序对类进行测试

#include <iostream>
using namespace std;

class CComplex{
private:
    double real;
    double imag;
public:
    CComplex(double r, double i=0){
        real = r;
        imag = i;
    }

    void show() const{
        if(imag >= 0)
            cout << real << "+" << imag << "i" << endl;
        else
            cout << real << imag << "i" << endl;  // imag本身就是负数
    }

    CComplex operator+(const CComplex &obj){
        return CComplex(real+obj.real, imag+obj.imag);
    }
};

int main(){
    CComplex a(1,2);
    CComplex b(3, -5);

    a.show();
    b.show();
    (a + b).show();
    return 0;
}

