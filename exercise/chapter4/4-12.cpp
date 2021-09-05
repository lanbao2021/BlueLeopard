// 4-12.cpp
// Created by 蓝同学 on 2021/8/8.
// 编写一个程序,输入一个句子(以句号结束) ,统计该句子中的,元音字母数、辅音字母数、空格数、数字数,及其他字符数。
#include <iostream>
using namespace std;
int main(){
    char ch;
    int num_y=0, num_f=0, num_space=0, num_digits=0, num_others=0;
    while(1){
        cin.get(ch);
        if(ch=='.'){
            cout << "元音字母数:" << num_y;
            cout << "辅音字母数:" << num_f;
            cout << "空格数:" << num_space;
            cout << "数字数:" << num_digits;
            cout << "其他字符数:" << num_others;
            break;
        }
        else if(ch==' ')
            num_space++;
        else if(ch > '0' && ch < '9')
            num_digits++;
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            switch (ch) {
                case 'a':case 'A':
                    case 'e':case 'E':
                        case 'i':case 'I':
                            case 'o':case 'O':
                                case 'u':case 'U': num_y++; break;
                                default: num_f++;
            }
        else
            num_others++;
    }
    return 0;
}

