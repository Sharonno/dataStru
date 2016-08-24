#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct hash_node {
        int data;
        int count;
        struct hash_node * next;
}HASH_NODE;

HASH_NODE * hash_table[1000000];
HASH_NODE * create_node(int &data) {

    HASH_NODE *node = (HASH_NODE*)malloc(sizeof(HASH_NODE));
    if (NULL == node) {
        printf("malloc node failed!/n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->count = 1;
    node->next = NULL;

}

/*
 * hash函数采用乘法散列法
 * h(k) = int(2^14*(0.618*k mod 1))
*/
int hash_function(int &key) {
    double result = 0.618 * key;
    return (int)(pow(2, 14) * (result - (int)result))
}

void insert(int& data) {  
    int index = hash_function(data);  
    HASH_NODE* pnode = hash_table[index];  
    while (NULL != pnode) {  
        if (pnode->data == data) { 

                pnode->count += 1;  
                return;  
        }  
        pnode = pnode->next;  
    }  
                      
    pnode = creat_node(data);  
    pnode->next = hash_table[index];
    hash_table[index] = pnode;
}

void destroy_node() {  
    HASH_NODE* p = NULL;  
    HASH_NODE* tmp = NULL;  
    for (int i = 0; i < HASHTABLESIZE; ++i) {  
        p = hash_table[i];  
        while (NULL != p) {  
            tmp = p;  
            p = p->next;  
            free(tmp);  
            tmp = NULL;  
        }  
    }  
}  

struct MIN_HEAP {
    int count;
    int data;
};
MIN_HEAP heap[10+1];
/*  
 * min_heapify函数对堆进行更新，使以i为跟的子树成最大堆 
*/
void min_heapify(MIN_HEAP* H, const int& size, int i) {
    int child_idx = 2 * i + 1;
    int parent_count = H[i].count;
    int parent_data = H[i].data;
    while (child_idx < size) {
        if (child_idx +1 < size && H[child_idx] < H[child_idx + 1])
            child_idx += 1;
        if (parent_count < H[child_idx].count) {
            H[i].data = H[child_idx].data;
            H[i].count = H[child_idx].count;

            i = child_idx;
            child_idx = 2 * i + 1;
        } else
            break;
    }
    H[i].data = parent_data;
    H[i].count = parent_count;
}


void build_min_heap(MIN_HEAP *H, const int & size) {
    for (int i = size/2+1; i>=1; i--) {
        min_heapify(H, size, i)
    }
}

/*
 * traverse_hashtale函数遍历整个hashtable，更新最小堆
 */
void traverse_hashtale() {
    HASH_NODE *p = NULL;
    for (int i = 0; i < 1000000; i++) {
        p = hashtable[i];
        while(p) {
            if (p->count > heap[1].count) {
                heap[1].count = p->count;
                heap[1].data = p->data;
                min_heapify(heap, 10, 1);
            }
            p = p->next;
        }
    }
}
int main() {
    for (int i = 1; i < 11; i++) {
        heap[i].data = i;
        heap[i].count = i;
    }
    build_min_heap(heap, 10);
    FILE* fp = fopen('', 'r');
    int num;
    while (!feof(fp)) {
        fscanf(fp, '%d', &num);
        insert(num);
    }
    fclose(fp);
    traverse_hashtale();
}
