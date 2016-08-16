#include "priQue.h"
#include <assert.h>
using namespace std;

template<class T>
PriorityQueue<T>::PriorityQueue(int maxSize):heap_size(0), max_size(maxSize) {
    heap = new T[maxSize];
}

template<class T>
void PriorityQueue<T>::enQueue(T *ele) {
   if (heap_size + 1> max_size) { //堆已满，需重新分配
        T *old_heap = heap;
        heap = new T[max_size * 2];
        for (int i = 0; i < heap_size; i++)
            heap[i] = old_heap[i];
        delete old_heap;
        old_heap = NULL;
   }
   heap[heap_size] = *ele;
   int curr_idx = heap_size;
   int par_idx = parent(heap_size);
   ++ heap_size;
   while (par_idx >= 0 && heap[curr_idx] > heap[par_idx]) {
        T tmp = heap[curr_idx];
        heap[par_idx] = tmp;
        curr_idx = par_idx;
        par_idx = parent(curr_idx);
   }       
}

template<class T>
void PriorityQueue<T>::deQueue(T * ele) {
    heap[0] = heap[heap_size - 1];
    -- heap_size;
    heapify(heap, heap_size, 0);
}

template<class T>
T *PriorityQueue<T>::top() {
    return &heap[0];
}

/*下标为奇数的元素为左孩子,偶数为右孩子
 * 下标为i的元素的左孩子为(2*i+1),右孩子为(2*i+2);i从0开始。
 * 根据这个式子反推就可以了
 * */
template<class T>
int PriorityQueue<T>::parent(int i) {
    return (i % 2) == 0? (i - 2)/2: (i - 1)/2; 
}
