#include<stdio.h>
using namespace std;

template<class T> void heapify(T *array, const int length, int i) {
    if (i < length) {
        int parent_idx = i;
        int parent_val = array[parent_idx];
        int child = 2 * i + 1;
        while (child < length) {
            if (child + 1 < length && array[child] < array[child+1])
                child ++;
            if (parent_val < array[child]) {
                array[parent_idx] = array[child];
                parent_idx = child;
                child = 2 * p + 1;
            } else
                break;
        }
        array[parent_idx] = parent_val;
        //此时子树已经迭代完成，孩子中没有更大的了，不会上移，parent_val也不会下移了
    }
};

//这里实现的是最优先级队列
template<class T> class PriorityQueue {
    public:
        PriorityQueue(int maxSize = 20);
        PriorityQueue();
        ~PriorityQueue();
        void enQueue(T *ele);
        void deQueue(T *ele);
        inline T *top();
    private:
        inline int parent(int i);
    private:
        int heap_size;
        int max_size;
        T *heap;
        
};
