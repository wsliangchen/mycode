#include <bits/stdc++.h>
using namespace std;
/**
 * 匹配每个子串的最长公共前缀
 */
int d[10010];
void getNext(char *s, int *d) {
    int i = 1, l = 0;
    d[0] = strlen(s);
    for (; s[i]; i++) {
        int k, r = l + d[l];
        if (i < r)
            k = min(d[i - l], r - i);//映射到开头
        else
            k = 0;
        for (; s[i + k]; k++)
            if (s[i + k] != s[k])
                break;
        d[i] = k;
        if (i + k > r)
            l = i;
    }
}

void getNext_CFOriginal(char *s, int *z) {
    int l = 0, r = 0, n = strlen(s);
    z[0] = n;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l; //映射到开头
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    char *s = "aaaaac";
    int z[100];
    getNext_CFOriginal(s, z);
    for (int i = 0; i < strlen(s); i++)
        printf("%d ", z[i]);
    printf("\n");
    getNext(s, z);
    for (int i = 0; i < strlen(s); i++)
        printf("%d ", z[i]);

    return 0;
}