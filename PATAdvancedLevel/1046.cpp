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

int sum[100100];

int main(int argc, char const *argv[]) {
    int n,t,a,b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        sum[i + 1] += sum[i] + t;
    }
    int total = sum[n+1];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a,&b);
        int x = sum[max(a,b)] - sum[min(a,b)];
        printf("%d\n", min(x,total-x));
    }

    return 0;
}