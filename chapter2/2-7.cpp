// 2-7.cpp
// Created by 蓝同学 on 2021/7/5.
// 假设校园电费为0。6元/千瓦时，输入这个月使用了多少千瓦时的电，计算处需要交的电费。
// 假如你只有1元、5角和1角的硬币，请问各需要多少1元、5角和1角的硬币？
// 例如：这个月使用的电量是11
#include <iostream>
using namespace std;
int main()
{
    const int FEE = 6; // 以角为单位
    int amount, money;

    cout << "请输入本月的用电量" << endl;
    cin >> amount;

    money = amount * FEE;

    cout << "你本月的电费是：" << money / 10 << "元" << money % 10 << "角" << endl;
    cout << "你需要支付" << money / 10 << "个1元硬币，";
    cout << money % 10 / 5 << "个5角的硬币，";
    cout << money % 5 << "个1角的硬币，" << endl;
    return 0;
}

