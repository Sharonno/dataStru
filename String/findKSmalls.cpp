#include <iostream>
#include <vector>
using namespace std;

void min_heap(vector<int> &vec, int i, int len) {
    int p_val = vec[i];
    int c_idx = 2 * i + 1;
    while (c_idx < len) {
        if (c_idx + 1 < len && vec[c_idx] > vec[c_idx + 1])
            c_idx += 1;
            
        if (vec[c_idx] < p_val) {
            vec[i] = vec[c_idx];
            i = c_idx;
            c_idx = 2 * i + 1;
        } else
            break;
    }
    vec[i] = p_val;
}

void max_heap(vector<int> &vec, int i, int len) {
    int p_val = vec[i];
    int c_idx = 2 * i + 1;
    while (c_idx < len) {
        if (c_idx + 1 < len && vec[c_idx] < vec[c_idx + 1])
            c_idx += 1;
            
        if (vec[c_idx] > p_val) {
            vec[i] = vec[c_idx];
            i = c_idx;
            c_idx = 2 * i + 1;
        } else
            break;
    }
    vec[i] = p_val;
}

void min_heap_sort () {
   int arr[] = {11, 2 ,23, 14};
   vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

// 小根堆 降序排序
    for (int i = vec.size() / 2 + 1; i >= 0; i--)
        min_heap(vec, i, vec.size());
        
    for (int i = vec.size() -1; i >= 0; i--) {
        swap(vec[0], vec[i]);
        min_heap(vec, 0, i);
    }
}
vector<int> findKthSmall(vector<int>A, int n, int k) {
    vector<int> myheap(A.begin(), A.begin() + k);
    for (int i = myheap.size()/2+1; i >= 0; i--)
        max_heap(myheap, i, myheap.size());
    for (int i = k; i < n; i++) {
        if (A[k] < myheap[0]) {
            myheap[0] = A[k];
            max_heap(myheap, 0, i);
        }
    }
    return myheap;
}
using namespace std;

int main()
{

    vector<int> ans = findKthSmall(vec, vec.size(), 2);
    int privot = ans[-1];
    vector<int> v;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] <= privot)
            v.push_back(vec[i]);
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
   return 0;
}

