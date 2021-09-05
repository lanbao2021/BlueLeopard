// 5-9.cpp
// Created by 蓝同学 on 2021/8/15.
//
#include <iostream>
using namespace std;
int main(){
    char article[10][80];
    int i, j, digit=0, space=0, ch=0, other=0;
    cout << "input ten row of words, end with enter\n";
    for (i=0; i<10; ++i){
        cout << "input line_" << i << ":";
        for (j=0; j<80; ++j){
            cin.get(article[i][j]);
            if (article[i][j] == '\n'){
                article[i][j] = '\0';
                break;
            }
        }
    }

    for (i=0; i<80; ++i)


    return 0;
}
