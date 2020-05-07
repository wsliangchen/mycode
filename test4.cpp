#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n, m, t, res;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &t);
        int d1 = 0, d2 = 0;
        if (t <= num[0]) {
            res = 0;
        } else if (t >= num[n - 1]) {
            res = n - 1;
        } else {
            int l = 0, r = n - 1, m;
            while (r >= l) {
                m = l + (r - l) / 2;
                if (num[m] == t) {
                    res = m;
                    break;
                } else if (num[m] > t) {
                    d1 = num[m] - t;
                    r = m - 1;
                } else {
                    d2 = t - num[m];
                    l = m + 1;
                }
                res = (d1 < d2 ? (r + 1) : (l - 1));
            }
        }
        printf("%d\n", num[res]);
    }
    return 0;
}
