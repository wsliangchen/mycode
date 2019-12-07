#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;
const int N = 110;
int n, m;
int g[N][N];
int d[N][N];

typedef pair<int, int> pii;

queue<pii> q;

int bfs() {
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && g[x][y] == 0 &&
                d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs();
    return 0;
}