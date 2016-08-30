#include <iostream>

using namespace std;
void Insertsort1(int a[], int n)  
{  
    int i, j, k;  
    for (i = 1; i < n; i++)  
    {  
        //为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置  
        for (j = i - 1; j >= 0; j--)  
            if (a[j] < a[i])  
                break;  
  
        //如找到了一个合适的位置  
        if (j != i - 1)  
        {  
            //将比a[i]大的数据向后移  
            int temp = a[i];  
            for (k = i - 1; k > j; k--)  
                a[k + 1] = a[k];  
            //将a[i]放到正确位置上  
            a[k + 1] = temp;  
        }  
    }  
} 
void Insertsort2(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            int tmp = arr[i];
            int j;
            for (j = i - 1; j >=0 && arr[j] > tmp; j--)
                arr[j+1] = arr[j];
            arr[j+1] = tmp;
        }
    }
}

void Shellsort(int *arr, int n) {
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            if (arr[i] < arr[i - gap]) {
                int tmp = arr[i];
                int j;
                for (j = i - gap; j >= 0 && arr[j] > tmp; j -= gap)
                    arr[j + gap] = arr[j];
                arr[j+gap] = tmp;
            }
        }
    }
}
void Selectsort(int *arr, int n) {
    int i, j, min_idx;
    for (i = 0; i < n; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}
/*
void MergeArr(int *a, int m, int *b, int n, int c) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];
}*/
void MergeArr(int *arr, int begin, int end, int *copy) {
    int i = begin, mid = (begin + end) /2 ;
    int j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j])
            copy[k++] = arr[i++];
        else
            copy[k++] = arr[j++];
    }
    while (i <= mid)
        copy[k++] = arr[i++];
    while (j <= end)
        copy[k++] = arr[j++];
    
    for (i = 0; i < k; i++)
        arr[i + begin] = copy[i];
}

void Mergesort(int *arr, int begin, int end, int *copy) {
    if (begin < end) {
        int mid = (begin + end) / 2; 
        Mergesort(arr, begin, mid, copy);
        Mergesort(arr, mid+1, end, copy);
        MergeArr(arr, begin, end, copy);
    }
}
void mergesort(int *arr, int n) {
    int *copy = new int[n];
    Mergesort(arr, 0, n-1, copy);
    delete [] copy;
}
void Quicksort(int *arr, int begin, int end) {
    int i = begin, j = end;
    int key = arr[0];
    while (i < j) {
        while (key <= arr[j] && i < j)
            j --;
        arr[i] = arr[j];
        while (key >= arr[i] && i < j)
            i ++;
        arr[j] = arr[i];
    }
    arr[i] = key;
}
int main()
{
   cout << "Hello World" << endl; 
   int arr[] = {4, 3, 1, 5};
//   Insertsort1(arr, 4);
    // Insertsort2(arr, 4);
    // Shellsort(arr, 4);
    // Selectsort(arr, 4);
    // mergesort(arr, 4);
    Quicksort(arr, 0, 3);
   for (int i = 0; i < 4; i++)
    cout << arr[i] << " ";
   return 0;
}

