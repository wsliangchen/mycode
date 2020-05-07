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
    ll n;
    scanf("%lld", &n);
    ll i = 2, ans = 1,flag = 0;
    while (n != 1) {
        if (n % i == 0) {
            if (flag == 0) {
                ans *= i;
                flag = 1;
            }
            n /= i;
        } else
            i++,flag = 0;
    }
    printf("%lld", ans);
    return 0;
}