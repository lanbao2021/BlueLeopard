// 10-8.cpp
// Created by 蓝同学 on 2021/9/2.
//
#include <iostream>
using namespace std;


class Joseph{
private:
    struct node{
        int data;
        node *next;
        node(int d, node *n=NULL):data(d), next(n){}
    };
    node *head;
public:
    Joseph(int n);
    ~Joseph();
    void simulate();
};

Joseph::Joseph(int n) {
    node *tail;

    head = tail = new node(0); // head指向表头，没有头节点
    for (int i=1; i<n; ++i){
        tail->next = new node(i);
        tail = tail->next;
    }
    tail->next = head; // 头尾相连
}

Joseph::~Joseph(){
    node *p, *q;
    q=head; // 报数1
    while(q->next != q){
        p = q->next; // 报数2
        q = p->next; // 报数3，被干掉
        p->next = q->next; // 绕过q
        cout << q->data << '\t'; // 打印q的编号
        delete q; // 干掉q
        q = p->next; // q重新指向接下去报数1的结点
    }
}

int main(){

    return 0;
}
