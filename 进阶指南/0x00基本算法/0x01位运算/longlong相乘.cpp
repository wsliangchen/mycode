#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mul1(ll a, ll b, ll p) {
    ll ans = 0;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

ll mul2(ll a, ll b, ll p) {
    a %= p, b %= p;
    ll c = (double)a * b / p;
    ll ans = a * b - c * p;
    if (ans < 0)
        ans += p;
    else if (ans >= p)
        ans -= p;
    return ans;
}

int main(int argc, char const *argv[]) {
    ll a = 123456789123456789, b = 987654321987654321, p = 1e15+7;
    printf("%lld\n", mul1(a,b,p));
    printf("%lld\n", mul2(a,b,p));
    return 0; 
}