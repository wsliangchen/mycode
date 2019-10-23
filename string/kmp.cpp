#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int suffix[100];

void calsuffix(char *p) {
    suffix[0] = -1, suffix[1] = 0;
    int k = 0, len = strlen(p);
    for (int i = 2; i <= len; i++) {
        while (k >= 0 && p[k] != p[i-1])
            k = suffix[k];
        suffix[i] = ++k;
    }
}

void getNext(char *p, int *next) {
    int j = 0, k = -1, len = strlen(p) - 1;
    next[0] = -1;
    while (j < len) {
        if (k == -1 || p[j] == p[k])
            j++, k++, next[j] = k;
        else
            k = next[k];
    }
}

int main(int argc, char const *argv[]) {
    char *p = "abaabcac";
    calsuffix(p);
    for (int i = 0; i < strlen(p); i++) {
        printf("%d ", suffix[i]);
    }
    printf("\n");
    int next[100];
    getNext(p, next);
    for (int i = 0; i < strlen(p); i++) {
        printf("%d ", next[i]);
    }
    return 0;
}