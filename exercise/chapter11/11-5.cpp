// 11-5.cpp
// Created by 蓝同学 on 2021/9/5.
// 二维数组可以看成是一维数组的一维数组
// 如table是一个3行4列的数组，那么table可以看成有3个元素
// table[0] table[1] table[2]
// table[i]是一个由4个元素组成的一维数组的名字
// 因而table[i]是一个指向double的指针
// 所以table是二级指针
#include <iostream>
#include <cassert>
using namespace std;

class Matrix{
    int row;
    int col;
    double **data;
public:
    Matrix(int r=1, int c=1);
    Matrix(const Matrix &other);
    double &operator()(int r, int c);
    ~Matrix();
};

Matrix::Matrix(int r, int c):row(r), col(c) {
    data = new double*[r]; // 注意这个*
    for(int i=0; i<r; ++i)
        data[i] = new double[c];
}
Matrix::Matrix(const Matrix &other) {
    int i, j;
    row = other.row;
    col = other.col;
    data = new double*[row]; // 注意这个*
    for(i=0; i<row; ++i)
        data[i] = new double[col];
    for(i=0; i<row; ++i)
        for(j=0; j<col; ++j)
            data[i][j] = other.data[i][j];
}

Matrix::~Matrix() {
    for(int i=0; i<row; ++i) // 二维数组的删除
        delete [] data[i];
    delete [] data;
}

double &Matrix::operator()(int r, int c) {
    assert(r<row && c<col); // 检查一下下标的合理性即可
    return data[r][c];
}

int main(){
    return 0;
}