#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getCommonLen(string s) {
        int n = s.length();
        vector<int> arr(n, -1);
        int j = -1;
        for (int i = 1; i < n; i++) {
            while (j >= 0 && s[i] != s[j+1]) j = arr[j];
            if (s[i] == s[j + 1]) j ++;
            arr[i] = j;
        }
        return arr;
}
int findAppearance(string A, int m,string B, int n) {
        
        if (B.empty()) return 0;
        if (A.empty()) return -1;
        // int m = haystack.length(), n = needle.length();
        vector<int> arr(m, -1);
        arr = getCommonLen(B);
        int j = -1;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && A[i] != B[j + 1]) j = arr[j];
            if (A[i] == B[j + 1]) j++;
            if (j == n-1) return (i - n + 1);
        }
        return -1;
    }
int main()
{
   cout << "Hello World" << endl; 
   string a = "acbc";
   string b = "bc";
   int c = findAppearance(a, 4, b, 2);
   cout << c << endl;
   return 0;
}

