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

int main(int argc, char const *argv[]) {
    ll p[6];
    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%lld", &p[i]);
    }
    sort(p, p + 5);
    for (int i = 4; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if(p[i] == 0) break;
            if(p[i] >= p[j]){
                ans += p[j];
                p[i] -= p[j];
                p[j] = 0;
            }else {
                ans += p[i];
                p[j] -= p[i];
                p[i] = 0;
                break;
            }
        }
    }

    printf("%lld", ans);
    return 0;
}