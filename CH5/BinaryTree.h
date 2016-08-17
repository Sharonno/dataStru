using namespace std;
//二叉树链表存储二叉树
template<class T> struct BiNode {
    T data;
    BiNode<T> *lChild;
    BiNode<T> *rChild;
};

template<class T>class BiTree {
    private:
        void Create(BiNode<T>* &R, T data[], int i, int n);
        void Release(BiNode<T> *R);
    public:
        BiNode<T> *root;
        BiTree(T data[], int n);
        void PreOrder(BiNode<T> *R);
        void InOrder(BiNode<T> *R);
        void PostOrder(BiNode<T> *R);
        void LevelOrder(BiNode<T> *R);
        ~BiTree();

};


template<class T> class SNode {
    public:
        BiNode<T> *R;
        int tag; //栈结点标记 1左子树 2右子树
};
