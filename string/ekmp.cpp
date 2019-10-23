#include <bits/stdc++.h>

using namespace std;

void getNext(string &T, int *next) {
    int a = 0, p = 0, m = T.length();
    next[0] = m;
    for (int i = 1; i < m; i++) {
        if (i >= p || i + next[i - a] >= p) {
            if (i >= p)
                p = i;
            while (p < m && T[p] == T[p - i])
                p++;
            next[i] = p - i;
            a = i;
        } else
            next[i] = next[i - a];
    }
}

int main(int argc, char const *argv[]) {
    string a = "aaaaac";
    int next[100];
    getNext(a, next);
    for(int i = 0; i < a.length(); i++)
    {
        printf("%d ", next[i]);
    }
    
    return 0;
}