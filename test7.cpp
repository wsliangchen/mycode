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

bool boole[31][31];
bool vis[31];
int x[31];
int y[31];
int r[31];
int n = 0, maxx = -1;
void dfs(int step) {
    if (step > n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                sum += (r[i] * r[i]);
            }
        }
        maxx = max(sum, maxx);

        return;
    }

    vis[step] = false;
    dfs(step + 1);
    for (int i = 1; i < step; i++) {
        if (vis[i] && !boole[i][step]) {
            return;
        }
    }
    vis[step] = true;
    dfs(step + 1);
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool bo =
                ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) >
                 (r[i] + r[j]) * (r[i] + r[j]));
            boole[i][j] = bo;
            boole[j][i] = bo;
        }
    }
    dfs(1);
    printf("%d", maxx);
    return 0;
}