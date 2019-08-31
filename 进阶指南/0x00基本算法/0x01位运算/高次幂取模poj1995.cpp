#include <cstdio>
using namespace std;

int power(int a, int b, int m) {
    int ans = 1 % m;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = (long long)ans * a % m;
        a = (long long)a * a % m;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans = 0, m, n, a, b;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            ans = (ans + power(a, b, m)) % m;
        }
        printf("%d\n", ans);
    }
    getchar();
    return 0;
}