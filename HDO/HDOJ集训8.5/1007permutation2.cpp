#include <bits/stdc++.h>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;
int arr[1000];
int n = 4, x = 2, y = 4;

bool judge() {
    for (int i = 1; i < n; i++)
        if (abs(arr[i + 1] - arr[i]) > 2)
            return false;

    return true;
}
int fac(int x) {
    if (x == 1)
        return 1;
    return x * fac(x - 1);
}

int main(int argc, char const *argv[]) {
    for (int k = 3; k < 10; k++) {
        for (int l = 1; l < k - 1; l++) {
            for (int m = l + 1; m <= k; m++) {
                n = k, x = l, y = m;
                arr[1] = x;
                arr[n] = y;
                for (int i = 2, j = 1; i < n; i++, j++) {
                    if (j == x || j == y)
                        j++;
                    arr[i] = j;
                }
                int ans = 0;
                int fc = fac(n - 2);
                for (int i = 0; i < fc; i++) {
                    if (judge())
                        ans++;
                    next_permutation(arr + 2, arr + n);
                }
                printf("n = %d x = %d y = %d  ans = %d\n", n, x, y, ans);
            }
        }
    }
    getchar();
    return 0;
}