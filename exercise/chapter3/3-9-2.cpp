// 3-9-2.cpp
// Created by 蓝同学 on 2021/7/5.
// 编写一个程序，输入一个字母，判断该字母是元音还是辅音字母。
// 用switch实现
#include <iostream>
using namespace std;
int main()
{
    char ch;
    cin >> ch;

    if(ch >= 'a' && ch <= 'z') ch = ch - 'a' + 'A'; // 全部换成大写字母
    if(ch >= 'Z' || ch < 'A') cout << "不是字母" << endl;
    else
        switch(ch)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': cout << "是元音字母" << endl; break;
            default: cout << "是辅音字母" << endl;
        }
    return 0;
}

