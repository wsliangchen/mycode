#include <stdio.h>
short dAA[36];
short dAB[36];
void dS(short A[], long long V) {
    int i;
    for (i = 0; i < 36; i++) {
        A[i] = V & 1;
        V >>= 1;
    }
}
int main() {
    int i;
    int T;
    long long A, B;
    long long R;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &A, &B);
        dS(dAA, A);
        dS(dAB, B);
        if (dAA[35] && dAB[35]) {
            R = 1;
        } else {
            R = 0;
        }
        for (i = 34; i >= 0; i--) {
            R <<= 1;
            if (dAA[i] && dAB[i]) {
                R += 1;
            }
        }
        if (R) {
            printf("%lld\n", R);
        } else {
            printf("1\n");
        }
    }
}
