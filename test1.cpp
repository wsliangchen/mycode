#include <stdio.h>
#include <stdlib.h>

#define MAX 1010

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int x[MAX], c = 0, num = 1, i, j;
        x[0] = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < num; j++) {
                if (x[j] >= 5) {
                    x[j] = 2 * (x[j] - 5) + c;
                    c = 1;
                } else {
                    x[j] = 2 * x[j] + c;
                    c = 0;
                }
            }
            if (c == 1) {
                num++;
                c = 0;
                x[j] = 1;
            }
        }
        for (i = num - 1; i >= 0; i--)
            printf("%d", x[i]);
        printf("\n");
    }
    return 0;
}
