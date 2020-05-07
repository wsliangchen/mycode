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

int main(int argc, char const *argv[]){
    int l,r;
    scanf("%d%d", &l, &r);
    ll ans = 0;
    for(int i = l; i <= r; i++){
        for(int j = 0; j < 31; j++)
            if((i >> j)&1) ans++;
    }
    printf("%lld", ans);
    return 0;
}