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

int arr[1000010], n;

void shai(int a) {
    int t = 0;
    for (int i = 1; t <= n; i++) {
        t = a * i;
        arr[t] = 1;
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    int a, b, c, t, ans = 0;
    scanf("%d%d%d", &a, &b, &c);
    shai(a);
    shai(b);
    shai(c);
    for(int i = 1; i<=n; i++){
        if(arr[i] == 0) ans++;
    }
    printf("%d", ans);
    return 0;
}