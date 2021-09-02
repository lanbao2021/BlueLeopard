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
    for(int i=0; i<numOfStudent; ++i)
        delete [] sInfo[i].scoreQuiz;
    delete [] sInfo;
}

void Teacher::inputStudent() {
    for(int i=0; i<numOfStudent; ++i){
        cout << "input NO." << i << " student name:";
        cin >> sInfo[i].name;
    }
}

void Teacher::inputScore(Type scoretype) {
    int i;
    switch(scoretype){
        case MID:
            for(i=0; i<numOfStudent; ++i){
                cout << "请输入" << sInfo[i].name << "的期中成绩:" ;
                cin >> sInfo[i].scoreMid;
            }
            break;
        case FINAL:
            for(i=0; i<numOfStudent; ++i){
                cout << "请输入" << sInfo[i].name << "的期末成绩:";
                cin >> sInfo[i].scoreFinal;
            }
            break;
        case QUIZ:
            if(curQuiz > totalQuiz){
                cout << "所有测验都已完成！无法输入" << endl;
                return;
            }
            for(i=0; i<numOfStudent; ++i){
                cout << "请输入" << sInfo[i].name << "的测验成绩：" ;
                cin >> sInfo[i].scoreQuiz[curQuiz];
            }
            ++curQuiz;
    }
}

void Teacher::analysis(Type scoretype) {
    int i;
    int high=0, low=100, total=0, excellent=0, good=0, pass=0,fail=0;

    switch(scoretype){
        case MID:
            for(i=0; i<numOfStudent; ++i){
                total += sInfo[i].scoreMid;
                if(sInfo[i].scoreMid > high)
                    high = sInfo[i].scoreMid;
                if(sInfo[i].scoreMid < low)
                    low = sInfo[i].scoreMid;
                if(sInfo[i].scoreMid >= 90)
                    ++excellent;
                else if(sInfo[i].scoreMid >= 75)
                    ++good;
                else if(sInfo[i].scoreMid >= 60)
                    ++pass;
                else
                    ++fail;
            }
            break;
        case FINAL:
            for(i=0; i<numOfStudent; ++i){
                total += sInfo[i].scoreFinal;
                if(sInfo[i].scoreFinal > high)
                    high = sInfo[i].scoreFinal;
                if(sInfo[i].scoreFinal < low)
                    low = sInfo[i].scoreFinal;
                if(sInfo[i].scoreFinal >= 90)
                    ++excellent;
                else if(sInfo[i].scoreFinal >= 75)
                    ++good;
                else if(sInfo[i].scoreFinal >= 60)
                    ++pass;
                else
                    ++fail;
            }
            break;
        case QUIZ:
            int no;
            cout << "要统计几次测验成绩？";
            cin >> no;
            if(no >= curQuiz){
                cout << "还没进行测验无法统计" << endl;
                return;
            }
            for(i=0; i<numOfStudent; ++i){
                total += sInfo[i].scoreQuiz[no];
                if(sInfo[i].scoreQuiz[no] > high)
                    high = sInfo[i].scoreQuiz[no];
                if(sInfo[i].scoreQuiz[no] < low)
                    low = sInfo[i].scoreQuiz[no];
                if(sInfo[i].scoreQuiz[no] >= 90)
                    ++excellent;
                else if(sInfo[i].scoreQuiz[no] >= 75)
                    ++good;
                else if(sInfo[i].scoreQuiz[no] >= 60)
                    ++pass;
                else
                    ++fail;
            }
    }
    cout << "本次考试的最高分是：" << high << endl;
    cout << "本次考试的最低分是：" << low << endl;
    cout << "本次考试的平均分是：" << total / numOfStudent << endl;
    cout
    << "有" << excellent << "个同学优秀"
    << "有" << good << "个同学良"
    << "有" << pass+good+excellent << "个同学及格"
    << "有" << fail << "个同学不及格";
}



int main(){
    return 0;
}

