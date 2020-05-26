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

const int N = 510;

int g[N][N];
int dis[N], n, m;
bool st[N];

int dijkstra() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        }
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], dis[t] + g[t][j]);
    }
    if (dis[n] == 0x3f3f3f3f)
        return -1;
    return dis[n];
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra();
    return 0;
}