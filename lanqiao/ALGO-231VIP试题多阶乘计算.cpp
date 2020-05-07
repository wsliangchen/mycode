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
    int n,k,m;
    scanf("%d%d%d", &n,&k,&m);
    ll ans = 0;
    for(int i = 1; i <= k; i++)
    {
        ll t = 1;
        for(int j = n; j > 0; j-=i)
        {
            t *= j;
        }
        ans += t;
    }
    if(m == 1) printf("%lld", ans);
    else {
        char s[100];
        sprintf(s,"%lld",ans);
        ans = 0;
        for(int i = 0; i < strlen(s); i++)
        {
            ans += s[i]-'0';
        }
        printf("%lld", ans);
    }
    return 0;
}