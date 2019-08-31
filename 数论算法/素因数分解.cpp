#include <bits/stdc++.h>
using namespace std;
#define maxn 10000

int p[maxn], c[maxn];

//试除法
void divide(int n) {
    int m = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p[++m] = i, c[m] = 0;
            while (n % i == 0)
                n /= i, c[m]++;
        }
    }  
    if (n > 1) //n本身是素数
        p[++m] = n, c[m] = 1;
    for (int i = 1; i <= m; i++) {
        printf("%d^%d ", p[i], c[i]);
    }
}

int main(int argc, char const *argv[]) {
    divide(6);
    getchar();
    return 0;
}