// BCT2021-4.cpp
// Created by 蓝同学 on 2021/9/8.
// 从键盘逐行输入字符串保存到文件"D：//a.txt"中
// 然后把该文件的每一行字符串读入程序并显示
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream out("a.txt");
    if(!out)
        cout << "error!" << endl;
    cout << "input:";
    char ch = cin.get();
    while(ch != EOF){
        out << ch;
        ch = cin.get();
    }
    out.close();

//    ifstream in("a.txt");
//    if(!in)
//        cout << "error!!!!" << endl;
//    char ch1;
//    while((ch1 = in.get()) != EOF)
//        cout << ch;
    return 0;
}

