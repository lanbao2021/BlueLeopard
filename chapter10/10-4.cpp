// 10-4.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
using namespace std;

class savingAccount{
private:
    int no;
    double balance;
    static double rate;
    static int totalNo;
public:
    savingAccount(double deposit);
    void updateMonthly();
    void print() const;
    static void setRate(double);
    static int generateNo();
};

int savingAccount::totalNo = 0;
double savingAccount::rate = 0;

savingAccount::savingAccount(double deposit) {
    no = generateNo();
    balance = deposit;
}

void savingAccount::updateMonthly() {
    balance += balance * rate;
}

void savingAccount::print() const {
    cout << no << "\t" << balance << endl;
}

void savingAccount::setRate(double newRate) {
    rate = newRate;
}

int savingAccount::generateNo() {
    return ++totalNo;
}

int main(){
    return 0;
}

