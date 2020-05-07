#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;
int mod = 50000;

bool prime(int x){
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main(int argc, char const *argv[]){
    ll ans = 1,n;
    scanf("%lld", &n);
    for(int i = 2; ; i++){
        if(i != 2 && i & 1 == 0) continue;
        if(prime(i)){
            n--;
            ans = (ans*i)%mod;
            if(n == 0) break;
        }
    }
    printf("%lld", ans);

    return 0;
}