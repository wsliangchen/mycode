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
const int N = 4005;
int a[N],b[N],c[N],d[N];
int sum1[16000005],sum2[16000005];
int n,t;

int bsearch(int tar){
    int num = 0;
    int l = 0, r = t-1;
    while(l < r){
        int mid = l+(r-l)/2;
        if(tar <= sum2[mid])
            r = mid;
        else 
            l = mid+1;
    }
    while(sum2[l] == tar && l < t)
        num++,l++;
    return num;
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            sum1[t] = a[i]+b[j];
            sum2[t] = c[i]+d[j];
            t++;
        }
    sort(sum1, sum1+t);
    sort(sum2, sum2+t);
    int ans = 0;
    for(int i = t-1; i >= 0; i--){
        ans += bsearch(-sum1[i]);
    }
    printf("%d", ans);
    return 0;
}