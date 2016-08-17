#include"BinaryTree.h"
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
//当前结点i从1开始，左孩子2i，右孩子2i+1

template<class T> 
void BiTree<T>::Create(BiNode<T> *&R, T data, int i, int n) {
    if (i <= n) {
        R = new BiNode<T>;
        R -> data = data[i - 1];
        Create(R -> lChild, data, 2*i, n);
        Create(R -> rChild, data, 2*i+1, n);
    }
    else
        return R = NULL;
}

template<class T> void BiTree::Bitree(T data[], int n) {
    Create(root, data, 1, n);
}


//优化的非递归前序遍历：结点是在访问左子树后直接出栈
//时间复杂度：O(nlogn)
template<class T> 
void BiTree<T>::PreOrder(BiNode<T> *R){ //R是当前访问结点
    if (R == NULL) return;
    stack<BiNode *> stk;
    BiNode *node;
    node = R;
    while (node || !stk.empty()) {
        while (node){
            cout << node -> data;
            stk.push(node);
            node = node -> lChild;
        }
    }
    if (!stk.empty()) {
        node = stk.top();
        stk.pop();
        node = node -> rChild;

    }
}


//优化的非递归中序遍历：结点是在访问左子树后直接出栈
template<class T>
void BiTree<T>::InOrder(BiNode<T> *R) {
    if (R == NULL) return;
    stack<BiNode *>stk;
    BiNode *node = R;
    while (node || !stk.empty()) {
        while (node) {
            stk.push(node);
            node = node -> lChild;
        }
        if (!stk.empty()) {
            node = stk.top();
            stk.pop();
            cout << node -> data;
            p = p -> rChild;
        }
    } 
}

template<class T>
void BiTree<T>::PostOrder(BiNode<T> *R) {
//栈顶元素永远为当前元素的父结点
    if (R == NULL) return;
    BiNode * curr = T;
    BiNode * pre = NULL;
    stack<BiNode *> stk;
    stk.push(curr);
    while (!stk.empty()) {
        curr = stk.top();
        if ((curr -> lChild == NULL && curr -> rChild == NULL) ||
                (pre != NULL && (node -> lChild == pre || node -> rChild == pre))) {
            cout << node -> data;
            stk.pop();
            pre = curr;
        } else {
            if (curr -> rChild != NULL) 
                stk.push(cur -> rChild);
            if (curr -> lChild != NULL)
                stk.push(cur -> lChild);
        }
    }
}
