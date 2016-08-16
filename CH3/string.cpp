#include<stdio.h>
#include<vector>
using namespace std;

vector<int> getMatch(char *s) {
    int n = stren(s);
    vector<int> match(n, -1);
    int j = -1;
    for (int i = 1; i < n; i++) {
        while (j >= 0 && s[i] != s[j+1])
            j = match[j];
        if (s[i] == s[j+1]) j ++;
        match[i] = i;
    }
    return match;
}

int KMP(char *text, char *patt) {
    // return the index of first occurrence of pattern in text
    
    if (!*patt) return 0;
    if (!*text) return -1;
    int m = strlen(text), n = strlen(patt);
    vector<int> match = getMatch(patt);
    int j = -1;
    for (int i = 1; i < n; i++) {
        while (j>=0 && text[i] != patt[j+1])
            j = match[j];
        if (text[i] == patt[j+1]) j++;
        if (j == n-1) 
            return (i-n+1); // i-j
    }
    return -1;
}
