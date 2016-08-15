#include "SeqList.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    printf("Hello World!\n");
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    SeqList<int> mylist(a, 7);
    mylist.printList();

    return 0;
}
