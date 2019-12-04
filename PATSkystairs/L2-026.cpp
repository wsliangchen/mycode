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
const int N = 100010;

int fa[N], le[N], n, t, m = 1;

int dfs(int d) {
    if (d == -1)
        return 1;
    if (le[d] != 0)
        return le[d];
    else {
        le[d] = dfs(fa[d]) + 1;
        if(le[d] > m) m = le[d];
        return le[d];
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        fa[i] = t;
        if (t == -1)
            le[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    printf("%d\n", m);
    t = 0;
    for (int i = 1; i <= n; i++) {
        if(le[i] == m){
            printf("%s%d", t == 0?"":" ",i);
            t++;
        } 
    }
    return 0;
}