#include <cstdio>
#include <iostream>
using namespace std;

int arr[100010];

char s[maxl + 10], now[maxl + 10];
int p[2 * maxl + 10];
int manacher(char *s) {
    int len = strlen(s + 1), nas = 0;
    for (int i = 1; i <= len; i++)
        now[2*i-1] = '#', now[2*i] = s[i];
    len = len*2 + 1;
    now[len] = '#';
    int pos = 0, r = 0;
    
}

int main() {
    test(0);
    return 0;
}
