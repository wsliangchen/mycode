#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int e[510][510], vis[510];
int n, m;

void dfs(int x)
{
    vis[x] = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && e[x][i])
            dfs(i);
    }
}

int count()
{
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main(int argc, char const* argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x][y] = e[y][x] = 1;
    }
    int cnt = count();
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < n; j++) {
            if (e[x][j])
                e[x][j] = e[j][x] = 0;
        }

        int nowcnt = count();

        if (nowcnt - cnt > 1)
            printf("Red Alert: City %d is lost!\n", x);
        else
            printf("City %d is lost.\n", x);
        cnt = nowcnt;
        if (i == n - 1) {
            printf("Game Over.\n");
            break;
        } //国家的最后一个城市被占领
    }

    return 0;
}