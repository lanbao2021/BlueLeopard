// 3-11.cpp
// Created by 蓝同学 on 2021/7/5.
// 凯撒密码是将每个字母循环后移3个位置后输出。
// 如'a'变成'd'，'b'变成'e'，'z'变成'c'
#include <iostream>
using namespace std;
int main()
{
    char ch;

    cout << "请输入一个字母：";
    cin >> ch;

    if(ch >= 'a' && ch<='z')
        ch = (ch - 'a' + 3) % 26 + 'a';
    else if(ch >= 'A' && ch<='Z')
        ch = (ch - 'A' + 3) % 26 + 'A';
    cout << ch << endl;
    return 0;
}


