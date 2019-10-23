#include <cstdio>
#include <cstring>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;
const int maxl = 1000100;
char w[maxl], t[maxl];
int next[maxl];

void getnext() {
    next[0] = -1, next[1] = 0;
    int len = strlen(w), k = 0;
    for (int i = 2; i < len; i++) {
        while (k >= 0 && w[k] != w[i - 1])
            k = next[k];
        next[i] = ++k;
    }
}

int kmp() {
    getnext();
    int ans = 0, tlen = strlen(t), wlen = strlen(w);
    for (int i = 0, j = 0; i < tlen;) {
        if (t[i] == w[j])
            i++, j++;
        else {
            j = next[j];
            if (j == -1)
                i++, j++;
        }
        if (j == wlen) {
            ans++;
            i = i - wlen + 1;
            j = 0;
        }
        //printf("%d %d\n", i, j);
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    int ti;
    scanf("%d", &ti);
    while (ti--) {
        scanf("%s%s", w, t);
        printf("%d\n", kmp());
    }
    return 0;
}