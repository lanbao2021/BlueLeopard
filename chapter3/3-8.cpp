// 3-8.cpp
// Created by 蓝同学 on 2021/7/5.
// 编写一个计算薪水的程序。
// 某企业有3种工资计算方法:计时工资、计件工资和固定月工资。
// 程序首先让用户输入工资类别，再按照工资类别输入所需的信息。
// 若为计时工资，则输入工作时间及每小时薪水。
// 若为计件工资，则输入每件的报酬和本月完成的件数。
// 若为固定月工资，输入工资额，计算本月应发工资。
// 职工工资需要缴纳个人收入所得税，缴个税的方法是:
// 2000元以下免税;
// 2000~2500元者，超过2000元部分按5%收税;
// 2500~4000者，2000~2500的500元按5%收税，超过2500部分按10%收税;
// 4000元以上者，2000~ 2500的500元按5%收税，2500~4000的1500元按10%收税，超过4000元的部分按15%收税。
// 最后，程序输出职工的应发工资和实发工资。
#include <iostream>
using namespace std;
int main()
{
    char type;
    int time, piece;
    double salary, unitSalary;

    cout << "请选择工资类型：计时工资（T）、计件工资（P）、固定工资（S）:";
    cin >> type;

    // 计算应发工资
    switch(type)
    {
        case 'T':
        case 't':
            cout << "请输入工作时间和小时工资" << endl;
            cin >> time >> unitSalary;
            salary = time * unitSalary;
            cout << "工作时间：" << time << "小时，本月应发工资为：" << salary << endl;
            break;
        case 'P':
        case 'p':
            cout << "请输入完成数量和每件报酬：" << endl;
            cin >> piece >> unitSalary;
            salary = piece * unitSalary;
            cout << "完成件数：" << piece << "，本月应发工资为：" << salary << endl;
            break;
        case 'S':
        case 's':
            cout << "请输入月工资：" << endl;
            cin >> salary;
            cout << "本月应发工资为：" << salary << endl;
            break;
        default: cout << "错误的工资类型！" << endl; return 1;
    }

    // 计算实发工资
    double tmp = salary;
    if(tmp > 4000)
    {
        salary -= (tmp - 4000) * 0.15;
        tmp = 4000;
    }
    if(tmp > 2500)
    {
        salary -= (tmp - 2500) * 0.1;
        tmp = 2500;
    }
    if(tmp > 2000)
    {
        salary -= (tmp - 2000) * 0.05;
    }
    cout << "本月实发工资：" << salary << endl;
    return 0;
}

