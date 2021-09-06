// 12-3.cpp
// Created by 蓝同学 on 2021/9/6.
//
#include <iostream>
using namespace std;

class Shape{
protected:
    double x,y;
public:
    Shape(double xx, double yy){ x=xx; y=yy; }
    virtual double area() const { return 0.0; }
    virtual void display() const{
        cout << "This is a shape. The position is ("
        << x << ", " << y << ")\n";
    }
};

class Rectangle:public Shape{
protected:
    double w, h;
public:
    Rectangle(double xx, double yy, double ww, double hh):
    Shape(xx, yy), w(ww), h(hh){}
    // 继承时要在初始化列表里调用基类的构造函数
    // 如果只是组合的话只需要初始化对象成员就行

    double area() const { return w*h; } // 重定义虚函数area()
    void display() const { // 重定义虚函数display()
        cout << "This is a rectangle. The position is (" << x
        << ", " << y << ")\t";
        cout << "The width is " << w << ". The height is " << h << endl;
    }
};

class Circle:public Shape{
protected:
    double r;
public:
    Circle(double xx, double yy, double rr): Shape(xx, yy), r(rr){}
    double area() const { return 3.14*r*r; }
    void display() const {
        cout << "This is a Circle. The position is (" << x
        << ", " << y << ")\t";
        cout << "This radius is " << r << endl;
    }
};


int main(){
    Shape s(1,2), *sr;
    sr = &s;
    sr->display();
    cout << "The area is " << sr->area() << endl;
//    This is a shape. The position is (1, 2)
//    The area is 0

    Rectangle rect(3, 4, 5, 6);
    sr = &rect;
    sr->display();
    cout << "This area is " << sr->area() << endl;
//    This is a rectangle. The position is (3, 4)	The width is 5. The height is 6
//    This area is 30

    Circle c(7, 8, 9);
    sr = &c;
    sr->display();
    cout << "The area is " << sr->area() << endl;
//    This is a Circle. The position is (7, 8)	This radius is 9
//    The area is 254.34

    // 定义一个指针数组
    Shape *sp[3] = { &s, &rect, &c};
    for(int i=0; i<3; ++i){
        sp[i]->display();
        cout << "The area is " << sp[i]->area() << endl;
    }

    return 0;
}

