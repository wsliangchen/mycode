
#include <cstdio>
typedef long long ll;

using namespace std;
ll cal(ll a) {
    ll r = a % 6;
    if (r == 0)
        printf("%lld\n", a / 2);
    else if (r == 1)
        printf("%lld\n", (a / 6) * 4 + 1);
    else if (r == 2)
        printf("%lld\n", a / 2);
    else if (r == 3)
        printf("%lld\n", a / 6);
    else if (r == 4)
        printf("%lld\n", a - 1);
    else
        printf("%lld\n", a / 6);
}


int main(int argc, char const *argv[]) {
    int t;
    ll a;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &a);
        cal(a);
    }

    return 0;
}