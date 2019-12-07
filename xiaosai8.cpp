#include <algorithm>
#include <cstdio>
typedef long long ll;

using namespace std;

struct T {
    int x, y;
} t[5010];

bool cmp(T a, T b){
    return a.x < b.x;
}

//?? TLE
int main(int argc, char const *argv[]) {
    int n;
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &t[i].x, &t[i].y);
    }
    sort(t,t+n,cmp);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                if(t[j].y < t[i].y && t[j].y < t[k].y) ans ++;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}