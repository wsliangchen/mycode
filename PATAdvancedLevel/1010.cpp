#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int convto(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'a' + 10;
}

void conversion(char s[], char s2[], int d1, int d2) {
    long long i, j, t, num = 0;
    char c;
    for (i = 0; s[i] != '\0'; i++) {
        t = convto(s[i]);
        num = num * d1 + t;
    }
    i = 0;
    while (1) {
        t = num % d2;
        if (t <= 9)
            s2[i] = t + '0';
        else
            s2[i] = t + 'a' - 10;
        num /= d2;
        if (num == 0)
            break;
        i++;
    }
    for (j = 0; j < i / 2; j++)
        swap(s2[j], s2[i - j]);
    s2[i + 1] = '\0';
}

int main(int argc, char const *argv[]) {
    char s1[200000], s2[200000], temp[200000];
    int tag, radix;
    scanf("%s%s%d%d", s1, s2, &tag, &radix);
    if (tag == 2)
        swap(s1, s2);
    for (int i = 2; i <= 1e6; i++) {
        conversion(s1, temp, radix, i);
        if (strcmp(s2, temp) == 0) {
            printf("%d", i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}



