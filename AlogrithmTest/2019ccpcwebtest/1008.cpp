#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

using namespace std;
int df[100010];

int main(int argc, char const *argv[]) {
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        ll ans = 0;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &df[i]);
        int left = n - 1;
        sort(df, df + n);
        for (int i = n - 1; i >= 0; i--) {
            if (left != 0) {
                ll lt = df[i] / k;
                if (df[i] - lt > 0 && left - 1 >= lt)
                    left = left - lt - 1;
                else {
                    ans += df[i] - lt * k;
                    left = 0;
                }
            } else
                ans += df[i];
        }
        ans += (n-1)*k;
        printf("%lld\n", ans);
    }
    return 0;
}