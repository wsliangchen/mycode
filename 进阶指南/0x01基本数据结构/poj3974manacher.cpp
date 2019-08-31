#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
#define maxl 1000100
char s[maxl], now[2*maxl];
int p[2*maxl];

int manacher(char *s) {
    int len = strlen(s + 1), ans = 0;
    for (int i = 1; i <= len; i++)
        now[2 * i] = s[i], now[2 * i - 1] = '#';
    len = len * 2 + 1;
    now[len] = '#';
    int pos = 0, r = 0;
    for (int i = 1; i <= len; i++) {
        if (i < r)
            p[i] = min(p[pos - (i - pos)], r - i);
        else
            p[i] = 1;
        while (i - p[i] >= 1 && i + p[i] <= len &&
               now[i - p[i]] == now[i + p[i]])
            p[i]++;
        if (p[i] - 1 > ans)
            ans = p[i] - 1;
        if (i + p[i] > r) {
            pos = i;
            r = i + p[i];
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    s[0] = ' ';
    for (int i = 1;; i++) {
        scanf("%s", s + 1);
        if (s[1] == 'E')
            break;
        printf("Case %d: %d\n", i, manacher(s));
    }
    return 0;
}