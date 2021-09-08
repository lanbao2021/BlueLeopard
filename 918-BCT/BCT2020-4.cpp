// BCT2020-4.cpp
// Created by 蓝同学 on 2021/9/8.
// 定义一个时间类Time
// 通过运算符重载实现时间的比较(关系运算) 、
// 时间增加/减少若干秒(+=和-=) 、
// 时间增加/减少1秒(++和--) 、
// 计算两个时间相差的秒数(-)
// 以及输出时间对象的值(时—分—秒) 。
#include "iostream"
using namespace std;

class Time{
    friend int operator-(const Time &t1, const Time &t2) { return t1.second - t2.second; }
    friend ostream &operator<<(ostream &os, const Time &t);
    friend bool operator>(const Time &t1, const Time &t2) { return t1.second > t2.second; }
    friend bool operator>=(const Time &t1, const Time &t2) { return t1.second >= t2.second; }
    friend bool operator==(const Time &t1, const Time &t2) { return t1.second == t2.second; }
    friend bool operator!=(const Time &t1, const Time &t2) { return t1.second != t2.second; }
    friend bool operator<(const Time &t1, const Time &t2) { return t1.second < t2.second; }
    friend bool operator<=(const Time &t1, const Time &t2) { return t1.second <= t2.second; }
private:
    int second;
public:
    Time(int tt=0, int mm=0, int ss=0) { second = ss + mm*60 + tt*3600; }
    Time &operator++(){ ++second; return *this; } // 前缀++
    Time operator++(int x){ Time tmp=*this; ++second; return tmp; } // 后缀++
    Time &operator--() { --second; return *this; } // 前缀--
    Time operator--(int x) { Time tmp=*this; --second; return tmp; } // 后缀--
    Time &operator+=(const Time &other) { second += other.second; return *this; }
    Time &operator-=(const Time &other) { second -= other.second; return *this; }
};

ostream  &operator<<(ostream &os, const Time &t){
    int tt, mm, ss;
    tt = t.second / 3600;
    mm = t.second % 3600 / 60;
    ss = t.second % 60;

    os << tt << '-' << mm << '-' << ss;
    return os;
}

int main(){
    return 0;
}



