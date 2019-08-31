#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int e[1010][1010], vis[1010];
int n, m, k;

void dfs(int x)
{
    vis[x] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && e[x][i])
            dfs(i);
    }
}

int count(int x)
{
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    if (x >= 0)vis[x]  = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main(int argc, char const* argv[])
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x][y] = e[y][x] = 1;
    }
    int cnt = count(-1);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);

        int nowcnt = count(x);

        printf("%d\n", nowcnt-1);
    }

    return 0;
}