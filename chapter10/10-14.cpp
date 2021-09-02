// 10-14.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
#include <cstring>
using namespace std;

class Label{
private:
    char label[10];
    int no;
    char returnLabel[20];
public:
    Label(char *lb = "label"):no(1) { strcpy(label, lb); }
    void SetLabel(const char *s) { strcpy(label, s); }
    void SetInitNumber(int num) { no=num; }
    char *GetNextLabel();
};

char *Label::GetNextLabel() {
    char noChar[10];
    int tmpNo = no, i, j;

    if(no == 0){
        noChar[0] = '0';
        noChar[1] = '\0';
    }
    else{
        for(i = 9; tmpNo != 0; --i, tmpNo /= 10)
            noChar[i] = tmpNo % 10 + '0';
        for(j = 0, ++i; i<10; ++i, ++j)
            noChar[j] = noChar[i];
        noChar[j] = '\0';
    }

    strcpy(returnLabel, label);
    strcat(returnLabel, noChar);
    ++no;

    return returnLabel;
}

