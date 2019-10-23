#include <cstdio>

using namespace std;
#define maxl 1000100
int a[maxl], b[maxl], next[maxl];
int alen, blen;

void getnext() {
    next[0] = -1, next[1] = 0;
    int k = 0;
    for (int i = 2; i < blen; i++) {
        while (k >= 0 && b[k] != b[i - 1])
            k = next[k];
        next[i] = ++k;
    }
}

int kmp() {
    getnext();
    for (int i = 0, j = 0; i < alen;) {
        if (a[i] == b[j])
            j++, i++;
        else {
            j = next[j];
            if (j == -1)
                i++, j++;
        }
        if (j == blen)
            return i - j + 1;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &alen, &blen);
        for (int i = 0; i < alen; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < blen; i++)
            scanf("%d", &b[i]);
        printf("%d\n", kmp());
    }
    
    return 0;
}