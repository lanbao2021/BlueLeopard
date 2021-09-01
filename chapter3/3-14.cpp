// 3-14.cpp
// Created by 蓝同学 on 2021/7/6.
// 设计一停车场的收费系统。停车场有三类汽车，分别用三个字母表示。
// C代表轿车，B代表客车，T代表卡车。收费标准如下:
// 轿车 三小时内，每小时10元。三小时后，每小时15元
// 客车 两小时内，每小时20元。两小时后，每小时35元
// 卡车 一小时内，20元，一小时后，每小时30元
#include <iostream>
using namespace std;
int main()
{
    const int Fee3HourCar = 10, FeeForCar = 15;
    const int Fee2HourBus = 20, FeeForBus = 35;
    const int Fee1HourTruck = 20, FeeForTruck = 30;
    const int minAllDay = 1440;
    char type;
    int inHour, inMinute, outHour, outMinute, minute, hour, fee;
    // 输入车型
    cout << "请输入汽车类型(轿车C、客车B、卡车T):";
    cin >> type;
    if (type != 'c' && type != 'C' && type != 'B' && type != 'b' && type != 't' && type != 'T')
    {
        cout << "汽车类型错误!" << endl;
        return 0;
    }
    // 输入入库和出库时间
    cout << "请输入入库时间(时 分):";
    cin >> inHour >> inMinute;
    if (inHour < 0 || inHour > 23 || inMinute < 0 || inMinute > 59)
    {
        cout << "入库时间错误!" << endl;
        return 0;
    }
    cout << "请输入出库时间(时 分):";
    cin >> outHour >> outMinute;
    if (outHour < 0 || outHour > 23 || outMinute < 0 || outMinute > 59)
    {
        cout << "出库时间错误!" << endl;
        return 0;
    }
    // 计算停车时间
    minute = (outHour * 60 + outMinute - inHour * 60 - outMinute + minAllDay) % minAllDay;
    hour = minute / 60;
    if (minute % 60 != 0) ++hour; // 停车不足1小时按1小时计算
    
    // 根据不同的车型计算停车费
    switch (type)
    {
        case 'c':
        case 'C':
            if (hour <= 3) fee = Fee3HourCar * hour;
            else fee = 3 * Fee3HourCar + FeeForCar * (hour - 3);
            break;
        case 'b':
        case 'B':
            if (hour <= 2) fee = Fee2HourBus * hour;
            else fee = 2 * Fee2HourBus + FeeForBus * (hour - 2);
            break;
        case 't':
        case 'T':
            if (hour <= 1) fee = Fee1HourTruck;
            else fee = Fee1HourTruck + FeeForTruck * (hour - 1);
    }
    cout << "停车费为:" << fee << endl;
    return 0;
}

