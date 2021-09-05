// main_DoubleArray.cpp
// Created by 蓝同学 on 2021/9/3.
//
#include "DoubleArray_Operator.cpp"

int main(){
    DoubleArray array1(20, 30), array2;

    cin >> array1;
    cout << "array1:";
    cout << array1 << endl;

    array2 = array1;

    cout << "执行array2 = array1, array2：";
    cout << array2 << endl;

    // 利用==重载比较array1和array2
    cout << "array1 == array2 是" << ((array1 == array2) ? "true" : "false") << endl;

    array2[25] = 0;

    cout << "执行array2[25] = 0后，array1 == array2是" << ((array1 == array2) ? "true" : "false") << endl;

    array2 = array1(22, 25, 2);
    cout << "执行array2 = array1(22, 25, 2)后，array2的值为：" << array2 << endl;


    return 0;
}

//请输入数组元素[20,30]:
//1 2 3 4 5 6 7 8 9 10 11
//array1:数组内容为：
//1	2	3	4	5	6	7	8	9	10	11
//
//执行array2 = array1, array2：数组内容为：
//1	2	3	4	5	6	7	8	9	10	11
//
//array1 == array2 是true
//执行array2[25] = 0后，array1 == array2是false
//        执行array2 = array1(22, 25, 2)后，array2的值为：数组内容为：
//3	4	5	6