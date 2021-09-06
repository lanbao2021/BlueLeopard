// 12-2.cpp
// Created by 蓝同学 on 2021/9/6.
// 继承例题：汽车类和出租车类
#include <iostream>
#include <cstring>
using namespace std;

class car{
    char no[10];
    char owner[10];
    char type[20];
public:
    car(char *s1, char *s2, char *s3){
        strcpy(no, s1);
        strcpy(owner, s2);
        strcpy(type, s3);
    }

    void modifyNo(char *s) { strcpy(no, s); }
    void modifyOwner(char *s) { strcpy(owner, s); }
    const char *getNo() const { return no; }
    const char *getOwner() const { return owner; }
    const char *getType() const { return type; }
    void display() const{
        cout << no << '\t' << owner << '\t' << type;
    }
};

class taxi: public car{
    int seat;
    double price;
public:
    taxi(char *s1, char *s2, char *s3, int s, double p):car(s1, s2, s3){
        seat = s;
        price = p;

    }

    double operator()(int start, int end) { return price*(end-start); }
    int getSeat() const { return seat; }
    double getPrice() const { return price; }

    void display() const { // 重定义基类函数
        cout << getNo() << '\t' << getOwner() << '\t' << getType() << '\t'
        << seat << '\t' << price << endl;
    }
};

int main(){
    car car1("闽A8888", "Lan", "BMW");
    taxi taxi1("粤B1234", "Bao", "Audi", 5, 300);
    cout << car1.getNo() << " " << car1.getOwner() << " " << car1.getType() << endl;
    cout << taxi1.getNo() << " " << taxi1.getOwner() << " " << taxi1.getType() << endl;
    cout << taxi1(1000, 1005) << endl; // 起始里程和终点里程数乘以价格为费用
    return 0;
}

//闽A8888 Lan BMW
//粤B1234 Bao Audi
//1500

