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

int n, k;
int arr[100010], sum[100010];
int main(int argc, char const *argv[]) {
    scanf("%d%d", &n, &k);
    int t = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
                sum[i] = t;
        t += arr[i];
    }
    sum[n] = t;
    ll ans = 0;
    for (int i = 0; i < n+1; i++) {
        for (int j = i+1; j < n+1; j++) {
            if((sum[j] - sum[i])%k == 0) ans ++;
        }
    }
    printf("%lld", ans);
    return 0;
}