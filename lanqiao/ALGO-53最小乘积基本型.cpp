#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int a[100], b[100];
bool cmp(int x, int y) { return x > y; }
int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n, cmp);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] * b[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}