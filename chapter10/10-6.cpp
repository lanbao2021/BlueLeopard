// 10-6.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
#include <cstring>
using namespace std;

class Teacher{
private:
    char className[30];
    char time[20];
    char place[20];
    int numOfStudent;
    int totalQuiz;
    int curQuiz;

    struct Student{
        char name[10];
        int scoreMid;
        int scoreFinal;
        int *scoreQuiz;
    };

    Student *sInfo;
public:
    enum Type{MID, FINAL, QUIZ}; // 枚举类型，需要先定义一个枚举类型的变量
    Teacher(char *cName, char *cTime, char *cPlace, int noS, int noQuiz);
    ~Teacher();
    void inputStudent();
    void inputScore(Type);
    void analysis(Type);
};

Teacher::Teacher(char *cName, char *cTime, char *cPlace, int noS, int noQuiz):numOfStudent(noS), totalQuiz(noQuiz), curQuiz(0) {
    strcpy(className, cName);
    strcpy(time, cTime);
    strcpy(place, cPlace);
    sInfo = new Student[noS];
    for(int i=0; i<noS; ++i)
        sInfo[i].scoreQuiz = new int[noQuiz]; // sInfo是Student类型的动态数组，scoreQuiz是int类型的动态数组
}

Teacher::~Teacher() {
    for(int i=0;)
}


int main(){
    return 0;
}

