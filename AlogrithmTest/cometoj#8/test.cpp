#include <iostream>
#include <string>
#include <cstdio>
#include <map>
typedef long long ll;

using namespace std;
ll arr[100010];
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    ll sum = 0,sum2 = 0;//sum 所有数的合 sum2所有数的平方和
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        sum += arr[i];
        sum2 += arr[i]*arr[i];
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = sum2 + (n-2)*arr[i]*arr[i]-2*arr[i]*(sum-arr[i]);
        printf("%lld", ans);
        if(i != n-1) printf(" ");
    }
    return 0;
}