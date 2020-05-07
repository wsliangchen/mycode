#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

const int maxn = 1010;

char s[maxn], now[maxn * 2];
int p[2 * maxn];

int manacher(char *s) {
    int len = strlen(s + 1), ans = 0;
    for (int i = 1; i <= len; i++)
        now[2 * i - 1] = '#', now[2 * i] = s[i];
    len = len * 2 + 1;
    now[len] = '#';
    int pos = 0, r = 0;
    for (int i = 1; i <= len; i++) {
        if (i < r)
            p[i] = min(p[2 * pos - i], r - i);
        else
            p[i] = 1;
        while (i - p[i] >= 1 && i + p[i] <= len &&
               now[i - p[i]] == now[i + p[i]])
            p[i]++;
        if (p[i] - 1 > ans)
            ans = p[i] - 1;
        if (i + p[i] > r)
            pos = i, r = i + p[i];
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int i = 1;
    char c;
    while(scanf("%c", &c) && c != '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    printf("%d", manacher(s));  
    return 0;
}