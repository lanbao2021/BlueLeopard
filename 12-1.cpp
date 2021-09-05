// 12-1.cpp
// Created by 蓝同学 on 2021/9/5.
// 组合例题：Class Point, Segment, Triangle

#include <iostream>
#include <cmath>
using namespace std;

class Point{
    friend istream &operator>>(istream &is, Point &obj){
        is >> obj.x >> obj.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Point &obj){
        os << "(" << obj.x << "," << obj.y << ")" ;
        return os;
    }
private:
    double x,y;
public:
    Point(double a=0, double b=0){ x=a; y=b; }
    double getx() const { return x; }
    double gety() const { return y; }
};

// 线段类，两点构成一条线段
class Segment{
    friend istream &operator>>(istream &is, Segment &obj);
    friend ostream &operator<<(ostream &os, const Segment &obj);

private:
    Point start;
    Point end;
public:
    Segment(double x1=0, double y1=0, double x2=0, double y2=0):start(x1, y1), end(x2, y2){}
    Segment(Point p1, Point p2){ start = p1; end = p2; }
    double getLength() const;
    Point getMid() const;
    Point getStart() const { return start; }
    Point getEnd() const { return end; }
};

istream &operator>>(istream &is, Segment &obj){
    cout << "请输入起点坐标：";
    is >> obj.start;
    cout << "请输入终点坐标：";
    is >> obj.end;
    return is;
}

ostream &operator<<(ostream &os, const Segment &obj){
    os << obj.start << "-" << obj.end;
    return os;
}

double Segment::getLength() const {
    double x1 = start.getx();
    double x2 = end.getx();
    double y1 = start.gety();
    double y2 = end.gety();
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

Point Segment::getMid() const {
    return Point((start.getx() + end.getx())/2, (start.gety() + end.gety())/2 );
}



int main(){
    Point p1(1,1), p2(3,3);
    Segment s1, s2(p1, p2);
    cout << s1 << '\n' << s2 << endl;
    cin >> s1;
    cout << s1.getStart() << s1.getEnd() << s1.getMid() << endl;
    return 0;
}

/*
(0,0)-(0,0)
(1,1)-(3,3)
请输入起点坐标：2 2
请输入终点坐标：6 6
(2,2)(6,6)(4,4)
*/

