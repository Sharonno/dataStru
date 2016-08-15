#include "List.h"
#include <iostream>
using namespace std;

template<class T> 
SeqList<T>::SeqList(const T a[], int n){
    if (n > MAXSIZE) throw "max limit";
    for (int i = 0; i < n ; i++) 
        data[i] = a[i];
    length = n;

}


template<class T> 
void SeqList<T>::printList() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template<class T>
//头插法
LinkList<T>::LinkList(T a[], int n) {
    front = new ListNode<T>;
    front->next = NULL;
    for (int i = n - 1; i >= 0; i--) {
        ListNode<T> *node = new ListNode<T>;
        node -> data = a[i];
        node -> next = front -> next;
        front -> next = node;
    }
}

/*
 * 尾插法
template<class T>
LinkList<T>::LinkList_tail(T a[], int n) {
    front = new ListNode<T>;
    ListNode<T> *tail = front;
    for (int i = 0; i < n; i++) {
        ListNode<T> *node = new ListNode<T>;
        node -> data = a[i];
        tail -> next = node;
        tail = node; 
    }
    tail -> next = NULL; //终端结点的指针域设为空
}
*/
template<class T>
LinkList<T>::~LinkList() {
    ListNode<T> *p = front; //初始化工作指针p
    while (p) {
        front = p;
        p = p -> next;
        delete front;
    }
}

// 获取线性表第i个位置上的元素
template<class T>
ListNode<T> *LinkList<T>::get(int i) {
    ListNode<T> *p = front -> next;
    int j = 1;
    while (p && j != i) {
        p = p -> next;
        j ++;
    }
    return p;
}


//单链表的插入操作：在单链表的第i个位置插入值为x的元素
//前插操作：首先获得p所指元素的前一个元素的地址，设为q，然后对q所指元素进行后插操作。后插时间复杂度为O(1),前插时间复杂度为O(n)
//改进的前插操作：在p结点后插入新的结点，让新结点的数据域存储原来p结点的数据域，而p结点的数据域存储新插入结点的值（只考虑新结点和p），时间复杂度降为O(1)
//
template<class T>
void LinkList<T>::insert(int i, T x) {
    ListNode<T> *p = front;
    if (i != 1) p = get(i - 1); //如果不是在第一个元素插入，获得第i－1个元素的地址
    if (p) {
        ListNode<T> * node = new ListNode<T>;
        node -> data = p -> data;
        p -> data = x;
        node ->next = p -> next;
        p -> next = node;
    }

}

template<class T>
T LinkList<T>::deleteNode(ListNode *p) {
    // p 已经指向单链表中的某个结点
    T x = p -> data;
    ListNode<T> *tmp = p -> next;
    *p = *tmp;
    // the same as :
    //       p -> data = tmp -> data; 
    //       p -> next = tmp -> next;
    delete tmp;
    return x;
}


ListNode *LinkList<T>::middleElement() {
    ListNode<T> p = front;
    ListNode<T> q = front;
    while (p) {
        p = p -> next;
        if(q) q = q -> next;
        if(q) q = q -> next;
    }
    return p;
}

bool LinkList<T>::hasCircle() {
    if (front == NULL || front -> next == NULL) return false;
    ListNode<T> *p = front;
    ListNode<T> *q = front -> next;
    while (q && p != q) {
        p = p -> next;
        if(q) q = q -> next;
        if(q) q = q -> next;
    }
    if (q == NULL) return false;
    return true;

}


CLinkList<T>::CLinkList(T a[], int n) {
    ListNode *first, *p;
    for (int i = 0; i < n; i++) {
        if (i == 0) { 
            first = new ListNode<T>;
            first -> data = a[0];
            p = first;
        }
        else {
            ListNode *q = new ListNode<T>;
            q -> data = a[i];
            p -> next = q;
            p = p ->next;
        }
    }
    p -> next = first;
    return first;
}


CLinkList<T> *CLinkList<T>::connect(CLinkList<T> &a, CLinkList<T> &b) {
    CLinkList<T> *p = a;
    CLinkList<T> *q = b;
    while (p -> next != a)
        p = p -> next;
    while (q -> next != b) 
        q = q -> next;

    p -> next = b;
    q -> next = a;

    return a;
}



int main() {
    printf("Hello World!\n");
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    A x[2] = {A(10), A(12)};
    //SeqList<A> list_with_stru(x, 2);
    //list_with_stru.printList();
    SeqList<int> mylist(a, 7);
    mylist.printList();

    return 0;
}
