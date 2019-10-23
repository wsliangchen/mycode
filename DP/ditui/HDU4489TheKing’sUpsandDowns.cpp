#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long LL;

#define PI acos(-1.0)
using namespace std;

LL C[25][25];
LL d[25];
 int n, m;
void init(){
    for(int i = 0; i < 25; ++i) C[i][0] = 1;
    for(int i = 1; i < 22; ++i)
        for(int j = 1; j <= i; ++j)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
 
    d[0] = d[1] = 1;
    for(int i = 2; i < 21; ++i){
        LL ans = 0;
        for(int j = 0; j <= i; ++j)
            ans += d[j] * d[i-j-1] * C[i-1][j];
        d[i] = ans/2;
    }
}
 
int main(){
    init();
    int T;  cin >> T;
    while(T--){
        scanf("%d %d", &m, &n);
        printf("%d ", m);
        if(1 == n)  printf("1\n");
        else printf("%I64d\n", d[n]<<1);
    }
    return 0;
}