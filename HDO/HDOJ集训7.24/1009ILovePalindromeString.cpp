#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

char s[300020];
int ans[4000020];
bool judge(int a, int b)
{
    int mid = (a + b) / 2;
    while (a <= mid) {
        if (s[a] != s[b])
            return false;
        ++a;
        --b;
    }
    return true;
}


int main(int argc, char const* argv[])
{
    s[0] = '0';
    while (scanf("%s", &s[1])) {
        int len = strlen(s) - 1;
        printf("len = %d\n", len);
        for (int i = 1; i <= len; i++) {
            int l = 1, r = i, tans = 0;
            for (; r <= len; l++, r++) {
                if (judge(l, r) && judge(l, (l + r) / 2))
                    tans++;
            }
            ans[i] = tans;
        }
        for (int i = 1; i <= len; i++)
            printf("%d%s", ans[i], i == len ? "\n" : " ");

    }
    return 0;
}