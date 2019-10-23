#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;

const int maxl = 1000010;
using namespace std;

//O(n)找出最长回文字符串
char s[maxl + 5], now[2 * maxl + 5];
int p[2 * maxl + 5];
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
        //中心拓展  如不需要中心拓展判断一次即可
        while (i - p[i] >= 1 && i + p[i] <= len && now[i - p[i]] == now[i + p[i]])
            p[i]++;
        if (p[i] - 1 > ans)
            ans = p[i] - 1;
        if (i + p[i] > r) { //更新最大右边界
            pos = i;
            r = i + p[i];
        }
        //printf("i = %d pos = %d r = %d\n", i, pos, r);
    }
    return ans;
}



int main(int argc, char const *argv[]) { 
    int t;
    scanf("%d", &t);
    s[0] = ' ';
    while(t--){
        scanf("%s", s+1);
        printf("%d\n", manacher(s));
    }
    return 0; 
}