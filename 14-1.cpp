// 14-1.cpp
// Created by 蓝同学 on 2021/9/6.
// 写ASCII文件，读ASCII文件

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    // 写ASCII文件
    ofstream fout("test");
    if(!fout){
        cerr << "can't open output file.\n";
        return 1;
    }
    fout << 10 << " " << 123.456 << "\"This is a text file\"\n";
    fout.close();

    // 读ASCII文件-流提取运算符
    // 此方法遇到空白字符就停止读入了
    // 10 123.456"This
    ifstream fin("test");
    char s[80];
    int i;
    float x;

    if(!fin){
        cout << "can't open input file.\n";
        return 1;
    }
    fin >> i >> x >> s;
    cout << i << " " << x << s << endl;
    fin.close();

    // 读ASCII文件-getline方法
    // 可以读入空白字符
    // 10123.456"This is a text file"
    fin.open("test");
    fin >> i >> x;
    fin.getline(s, 80, '\n');
    cout << i << x << s << endl;
    fin.close();
    return 0;
}
