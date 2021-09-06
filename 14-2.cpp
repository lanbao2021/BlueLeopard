// 14-2.cpp
// Created by 蓝同学 on 2021/9/6.
// 二进制文件的读写
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream out("file"); // 定义输出流，并与文件file关联
    ifstream in; // 定义输入流对象
    fstream io; // 定义可以同时进行读和写的输入/输出流对象
    int i;

    // 将1～10写到输出流对象
    if(!out){
        cerr << "create file error.\n";
        return 1;
    }
    for(i=1; i<=10; ++i)
        out.write(reinterpret_cast<char *>(&i), sizeof(int));
    out.close();

    // 读入刚刚写的文件
    in.open("file");
    if(!in){
        cerr << "open file error.\n";
        return 1;
    }
    in.read(reinterpret_cast<char *>(&i), sizeof(int));
    while(!in.eof()){
        cout << i << " ";
        in.read(reinterpret_cast<char *>(&i), sizeof(int));
    }
    in.close();
    cout << endl;

    // 改写文件
    io.open("file");
    io.seekp(5 * sizeof(int)); // 第五个int数
    i = 20;
    io.write(reinterpret_cast<char *>(&i), sizeof(int));

    // 重新读取改写后的文件
    io.seekg(0);
    io.read(reinterpret_cast<char *>(&i), sizeof(int));
    while(!io.eof()){
        cout << i << " ";
        io.read(reinterpret_cast<char *>(&i), sizeof(int));
    }
    io.close();

    return 0;
}

