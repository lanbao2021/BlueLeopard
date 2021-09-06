// 13-2.cpp
// Created by 蓝同学 on 2021/9/6.
// 类模板的友元，定义某个类模板和函数模板为友元
#include <iostream>
using namespace std;

template <class elemType> class linkList;
template <class T> ostream &operator<<(ostream &os, const linkList<T> &obj);
template <class elemType> class Node;

template <class elemType>
class Node{
    friend class linkList<elemType>;
    friend ostream &operator<<(ostream &os, const linkList<elemType> &obj);

private:
    elemType data;
    Node<elemType> *next;
public:
    Node(const elemType &x, Node<elemType> *N=NULL){
        data = x;
        next = N;
    }
    Node():next(NULL){}
    ~Node(){}
};

template <class elemType>
class linkList{
    friend ostream &operator<<(ostream &os, const linkList<elemType> &obj);

protected:
    Node<elemType> *head;
    void makeEmpty(); // 清空链表
public:
    linkList(){ head = new Node<elemType>; }
    ~linkList() { makeEmpty(); delete head; }
    void create(const elemType &flag);
};

template<class elemType>
void linkList<elemType>::makeEmpty() {
    Node<elemType> *p = head->next;
    Node<elemType> *q;

    head->next = NULL;
    while(p!=NULL){
        q = p->next;
        delete p;
        p = q;
    }
}

template<class elemType>
void linkList<elemType>::create(const elemType &flag) {
    elemType tmp;
    Node<elemType> *p, *q = head;

    cout << "please input the linkList's data:" << flag << " is the symbol of end" << endl;
    while(true){
        cin >> tmp;
        if(tmp == flag)
            break;
        p = new Node<elemType>(tmp);
        q->next = p;
        q = p;
    }
}

template <class T>
ostream &operator<<(ostream &os, const linkList<T> &obj){
    Node<T> *q = obj.head->next;
    os << endl;
    while(q!=NULL){
        os << q->data;
        q = q->next;
    }
    return os;
}

int main(){
    linkList<int> intList;
    intList.create(0);
//    cout << intList;  // 这行代码执行不了，在CLion中会报错
    return 0;
}

