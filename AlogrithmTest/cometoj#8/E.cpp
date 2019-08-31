#include <cstdio>
#include <unordered_map>
#include <cmath>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

unordered_map<ll, ll> mp;

ll d(ll x) {
    ll t = sqrt(x) + 1;
    for (ll i = 2; i <= t; i++)
        if (x % i == 0)
            return i;
    return x;
}
ll f(ll x) {
    if (x > 0 && x < 4)
        return 1;
    else {
        ll c = d(x);
        if (x % (c * c) == 0)
            return d(x) * f(x / (c * c));
        else
            return f(x / d(x));
    }
}

int main(int argc, char const *argv[]) {
    mp[0] = mp[1] = mp[2] = mp[3] = 1;
    for (ll i = 2; i <= 1e5; i++) {
        mp[i] = f(i) + mp[i-1];
    }
    int t;
    ll ans = 0;
    scanf("%d", &t);
    while (t--) {
        ll q;
        scanf("%lld", &q);
        if(q < 1e9) {printf("%lld", mp[q]);continue;}
        for (ll i = 1; i <= q; i++) {
            ll temp = f(i);
            // printf("i = %d  %lld\n",i, temp);
            ans += temp;
        }
        printf("%lld", ans);
    }

    return 0;
}