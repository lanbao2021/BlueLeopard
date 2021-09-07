// 16-2.cpp
// Created by 蓝同学 on 2021/9/7.
//
#include <iostream>
using namespace std;

template<class elemType>
class linkList{
private:
    struct Node{
        elemType data;
        Node *next;
        Node(const elemType &x, Node *N=NULL){ data=x; next=N; }
        Node():next(NULL){}
        ~Node(){}
    };
    Node *head;
    void makeEmpty();

public:
    linkList(){ head = new Node; }
    ~linkList() { makeEmpty(); delete head; }

    class Itr{
    private:
        Node *current; // 用指向Node的指针表示对象位置
    public:
        Itr(Node *p) { current=p; }
        bool operator() () const { return current!=NULL; }
//        bool isHead() const { return current==head; } 内嵌类无法访问主类的成员
        const elemType &operator* () const { current->data; }
        void operator++() { current = current->next; }

        friend class linkList<elemType>;
    };

    void insert(Itr &p, const elemType &x){
        p.current->next = new Node(x, p.current->next);
        p.current = p.current->next;
    }

    void erase(Itr &p){
        Node *q = p.current->next;
        if(!q)
            return;
        p.current->next = q->next;
        delete q;
    }
    Itr begin() { return Itr(head->next); }
    Itr GetHead() { return Itr(head); }
};

template<class elemType>
void linkList<elemType>::makeEmpty() {
    Node *p, *q;
    p = head->next;
    head->next = NULL;

    // 回收链表中的所有结点
    while(p != NULL){
        q = p->next;
        delete p;
        p = q;
    }
}

int main(){
    linkList<int> lq; // 定义一个整型容器
    linkList<int>::Itr itr = lq.GetHead(); // 定义一个指向lq头节点的迭代器对象

    for(int i=0; i<10; ++i)
        lq.insert(itr, 2*i + 1);
//    cout << "用迭代器输出：\n";
//    for(itr = lq.begin(); itr(); ++itr)
//        cout << *itr << '\t';

    // 插入0, 2, 4, 6, 8, 10, 12, 14, 16, 18
//    int i;
//    for(itr = lq.GetHead(), i=0; i<20; ++itr, i+=2)
//        lq.insert(itr, i);
//    cout << "\n插入0, 2, 4, 6, 8, 10, 12, 14, 16, 18后：\n";
//    for(itr = lq.begin(); itr(); ++itr)
//        cout << *itr << '\t';
//
//    // 删除0, 2, 4, 6, 8, 10, 12, 14, 16, 18
//    for(itr = lq.GetHead(); itr(); ++itr)
//        lq.erase(itr);
//
//    cout << "\n删除0, 2, 4, 6, 8, 10, 12, 14, 16, 18后：\n";
//    for(itr = lq.begin(); itr(); ++itr)
//        cout << *itr << '\t';

    return 0;
}

