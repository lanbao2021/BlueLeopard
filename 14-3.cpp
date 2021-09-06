// 14-3.cpp
// Created by 蓝同学 on 2021/9/6.
// 设计一个图书馆的书目管理系统
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

class Book{
    int no;
    char name[20];
    int borrowed;
public:
    Book(const char *s="", int total_no=0);
    void borrow(int readerNO);
    void Return();
    void display() const;
};

Book::Book(const char *s, int totalNo){
    no = totalNo;
    borrowed = 0;
    strcpy(name, s);
}

void Book::borrow(int readerNO) {
    if(borrowed!=0)
        cerr << "本书已被借走\n";
    else
        borrowed = readerNO;
}

void Book::Return() {
    if(borrowed == 0)
        cerr << "本书没有被借走\n";
    else
        borrowed = 0;
}

void Book::display() const {
    cout << setw(10) << no
    << setw(20) << name
    << setw(10) << borrowed
    << endl;
}


void initialize(); // 系统初始化
void addBook(); // 添加新书
void borrowBook(); // 借书
void returnBook(); // 还书
void displayBook(); // 显示所有的书目信息

int main(){
    int selector;

    while(true){
        cout << "0 -- 退出\n";
        cout << "1 -- 初始化文件\n";
        cout << "2 -- 添加书\n";
        cout << "3 -- 借书\n";
        cout << "4 -- 还书\n";
        cout << "5 -- 显示所有书目信息\n";
        cout << "请选择（0～5）：";
        cin >> selector;

        if(selector == 0)
            break;

        switch (selector) {
            case 1: initialize(); break;
            case 2: addBook(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: displayBook(); break;
        }
    }
    return 0;
}

void initialize(){
    ofstream outfile("book"); // 清空文件
    int no=0;

    outfile.write(reinterpret_cast<const char *>(&no), sizeof(int));
    outfile.close();
}

void addBook(){
    char ch[20];
    Book *bp;
    int no;
    fstream outfile("book");

    // 读入藏书量
    outfile.seekg(0);
    outfile.read(reinterpret_cast<char *>(&no), sizeof(int));

    // 生成需要添加的新书
    ++no;
    cout << "请输入书名：" ;
    cin >> ch;
    bp = new Book(ch, no);

    // 将书目信息添加到文件
    outfile.seekp(0, ios::end);
    outfile.write(reinterpret_cast<const char *>(bp), sizeof(*bp));
    delete bp;

    // 更新藏书量
    outfile.seekp(0);
    outfile.write(reinterpret_cast<char *>(&no), sizeof(int));
    outfile.close();
}

void borrowBook(){
    int bookNo, readerNo;
    fstream iofile("book");
    Book bk;

    cout << "请输入书号、读者号：";
    cin >> bookNo >> readerNo;

    // 后面的int是因为首行保存了馆藏总数
    // 根据馆藏号定位所需要读取的记录是在哪一行
    iofile.seekg((bookNo - 1) * sizeof(Book) + sizeof(int));
    // 读入一条记录，存入对象bk
    iofile.read(reinterpret_cast<char *>(&bk), sizeof(Book));
    // 调用成员函数修改借书标记字段
    bk.borrow(readerNo);
    // 按照馆藏号定位到所写记录
    iofile.seekp((bookNo - 1) * sizeof(Book) + sizeof(int));
    // 更新记录
    iofile.write(reinterpret_cast<const char *>(&bk), sizeof(Book));
    iofile.close();
}

void returnBook(){
    int bookNo;
    fstream iofile("book");
    Book bk;

    cout << "请输入书号：";
    cin >> bookNo;

    iofile.seekg((bookNo - 1) * sizeof(Book) + sizeof(int));
    iofile.read(reinterpret_cast<char *>(&bk), sizeof(Book));
    bk.Return(); // 复位借书标记

    iofile.seekp((bookNo - 1) * sizeof(Book) + sizeof(int));
    iofile.write(reinterpret_cast<const char *>(&bk), sizeof(Book));
    iofile.close();
}

void displayBook(){
    ifstream infile("book");
    Book bk;

    infile.seekg(sizeof(int)); // 跳过第一行的馆藏数，定位到第一条书目信息
    infile.read(reinterpret_cast<char *>(&bk), sizeof(Book));

    while(!infile.eof()){
        bk.display();
        infile.read(reinterpret_cast<char *>(&bk), sizeof(Book));
    }
    infile.close();
}



