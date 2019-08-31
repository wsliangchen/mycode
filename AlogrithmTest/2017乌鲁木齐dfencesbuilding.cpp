#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll p = 1e9 + 7, n;
ll power(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans*a % p;
        a = a*a % p;
    }
    return ans;
}
ll comb(ll n, ll m) {
    if (m > n)
        return 0;
    ll ans = 1;
    for (int i = 1; i <= m; i++) {
        ll a = (n + i - m) % p;
        ll b = i % p;
        ans = ans * (a * power(b, p - 2) % p) % p;
    }
    return ans;
}
ll lucas(ll n, ll m) {
    if (m == 0)
        return 1;
    return comb(n % p, m % p) * lucas(n / p, m / p) % p;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", i, (lucas(n,4)+lucas(n,2)+1)%p);
    }
    return 0;
}