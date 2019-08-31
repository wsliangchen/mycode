#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int e[510][510], w[510][510], dis[510], front[510], cost[510];
int n, m, s, d;
bool visit[510];

const int inf = 999999999;

int main(int argc, char const* argv[])
{
    scanf("%d%d%d%d", &n, &m, &s, &d);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    fill(cost, cost + 510, inf);
    for (int i = 0; i < m; i++) {
        int a, b, c, wt;
        scanf("%d%d%d%d", &a, &b, &c, &wt);
        e[a][b] = e[b][a] = c;
        w[a][b] = w[b][a] = wt;
    }
    dis[s] = 0;
    cost[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    front[v] = u;
                    cost[v] = cost[u] + w[u][v];
                } else if (dis[u] + e[u][v] == dis[v]) {
                    if (cost[u] + w[u][v] < cost[v]) {
                        front[v] = u;
                        cost[v] = cost[u] + w[u][v];
                    }
                }
            }
        }
    }
    vector<int> ans;
    int i = d;
    while(i != s){
        ans.push_back(i);
        i = front[i];
    }
    printf("%d", s);
    for(int i = ans.size()-1; i >= 0; i--)
        printf(" %d", ans[i]);
    
    printf(" %d %d", dis[d],cost[d]);
    return 0;
}