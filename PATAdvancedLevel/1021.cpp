#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int vis[10010], n;
vector<int> e[10010];
void dfs(int x)
{
    vis[x] = 1;
    for (int i = 0; i < e[x].size(); i++) {
        if (!vis[e[x][i]])
            dfs(e[x][i]);
    }
}

int component()
{
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans++;
        }
    }
    return ans;
}

int depth(int x)
{
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    int layer[n + 1]; //迭代记层深度
    layer[x] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < e[now].size(); i++) {
            if (!vis[e[now][i]]) {
                q.push(e[now][i]);
                vis[e[now][i]] = 1;
                layer[e[now][i]] = layer[now] + 1;
            }
        }
    }
    int maxres = -1;
    for (int i = 1; i <= n; i++)
        maxres = max(layer[i], maxres);

    return maxres;
}

int main(int argc, char const* argv[])
{
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int compn = component(); //求联通分量数
    if (compn > 1) {
        printf("Error: %d components\n", compn);
        return 0;
    }
    vector<int> v(n);
    int maxdep = -1;
    for (int i = 0; i < v.size(); i++) {
        memset(vis, 0, sizeof(vis));
        v[i] = depth(i + 1);
        if (v[i] > maxdep) maxdep = v[i];
    }
    for(int i = 0; i < v.size(); i++)
        if(v[i] == maxdep) printf("%d\n", i+1);
    return 0;
}