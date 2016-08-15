#include <iostream>
using namespace std;
const int MAXSIZE = 1000;

template<class T>
class SeqList {
public:
    SeqList(){length = 0;}
    SeqList(const T a[], int n);

    int getLength(){return length;}
    void printList();
    void Insert(int i, T x);
    T del(int i);
    T get(int i);
    int locate(T x);
private:
    T data[MAXSIZE];
    int length;
};

class A {
public:
    A(int i): data(i){}
    // in order to "cout << A"
    friend ostream &operator <<(ostream &stream, A &obj) {
        stream << obj.data;
        return stream;
    }
private:
    int data;
};


template<class T>
struct ListNode {
  T data;
  struct ListNode<T> *next;
};
/*
 *单链表：
    头指针：如果表为空，则头指针值为NULL；反之，头指针存储第一个结点的地址
    头结点：没有实际意义，方便链表操作
    存储时，前一个结点的next域存储下一个结点的地址；
    头结点的地址存储在头指针中，尾结点的地址不存储任何地址，通常置为空
 *
 */
template<class T>
class LinkList {
    public:
        LinkList() {front = new ListNode<T>; front->next = NULL;}
        LinkList(T a[], int n);
        ~LinkList();
        void printList();
        int getLength();
        ListNode<T> *get(int i);
        int locate(T x);
        void insert(int i, T x);
        T del(int i); //删除线性表的第i个元素，并将该元素返回
        T deleteNode(ListNode<T> *p)； // 时间复杂度O(1)
        ListNode<T> *middleElement();
        bool hasCircle();

    private:
        ListNode<T> *front; //头指针
};

/*
 *循环链表：将单链表的尾结点的指针域指向头结点
 设置一个尾指针来表示单循环链表，即设置一个rear指针指向单循环链表的最后一个结点
 * */
template<class T>
class CLinkList {
    public:
        CLinkList() {
            rear = new ListNode<T>;
            rear -> next = rear;
        }

        CLinkList(T a[], int n);
        ~CLinkList();
        CLinkList *connect(CLinkList<T> &a, CLinkList<T> &b);
    private:
        ListNode<T> *rear;
};
