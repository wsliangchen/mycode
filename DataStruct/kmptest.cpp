#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void prefix_table(char pattern[], int prefix[]) {
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while (i < strlen(pattern)) {
        if (pattern[i] == pattern[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = prefix[len - 1];
            } else {
                prefix[i] = len;
                i++;
            }
        }
    }
    for (int i = 0; i < strlen(pattern); i++) {
        printf("%2d", prefix[i]);
    }
}

void move_prefix_table(int prefix[], int n) {
    for (int i = n - 1; i > 0; i--) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

void kmp_search(char text[], char pattern[]) {
    int n = strlen(pattern);
    int m = strlen(text);
    int *prefix = (int *)malloc(sizeof(int) * n);
    prefix_table(pattern, prefix);
    move_prefix_table(prefix, n); //计算前缀表
    // text[i] len(text) = m
    // pattern[j] len(pattern) = n
    int i = 0, j = 0;
    while (i < m) {
        if (j == n - 1 && text[i] == pattern[j]) {
            printf("Found pattern at %d\n", i - j);
            j = prefix[j];
        }
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = prefix[j];
            if (j == -1) {
                i++;
                j++;
            }
        }
    }
}

void getnext(char *p, int *next) {
    int plen = strlen(p);
    next[0] = -1;
    int k = -1, j = 0;
    while (j < plen - 1) {
        if (k == -1 || p[j] == p[k]) {
            k++;
            j++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    printf("\nnext = ");
    for (int i = 0; i < plen; i++) {
        printf("%2d", next[i]);
    }
}

void getnextval(char *p, int *next) {
    int plen = strlen(p);
    next[0] = -1;
    int k = -1, j = 0;
    while (j < plen - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];
        } else
            k = next[k];
    }
    printf("\nnextval = ");
    for (int i = 0; i < plen; i++)
        printf("%2d", next[i]);
}

int KmpSearch(char *s, char *p, int *next) {
    int i = 0, j = 0, slen = strlen(s), plen = strlen(p);
    while (i < slen && j < plen) {
        if (j == -1 || s[i] == p[j]) {
            j++;
            i++;
        } else
            j = next[j];
    }

    if (j == plen)
        return i - j;
    else
        return -1;
}

int bf(char *s, char *p) {
    int i = 0, j = 0, slen = strlen(s), plen = strlen(p);
    while (i < slen && j < plen) {
        if (s[i] == p[j])
            i++, j++;
        else
            j = 0, i++;
    }
    if (j == plen)
        return i - j;
    else
        return -1;
}

int main(int argc, char const *argv[]) {
    char str[] = "aasdsasdabcabcd";
    char find[] = "abcabcd";
    puts(str);
    puts(find);
    int next[strlen(find)];
    getnext(find, next);
    getnextval(find, next);
    printf("\nkmpnsearch pattern at %d\n", KmpSearch(str, find, next));
    printf("bfsearch pattern at %d\n", bf(str, find));

    return 0;
}