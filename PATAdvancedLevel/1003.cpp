#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int inf = 99999999;
int e[510][510];

int n,m,c1,c2,weight[510],dis[510],num[510],w[510];

bool visit[510];

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &n,&m,&c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0]+510*510,inf);
    fill(dis,dis+510,inf);
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;

    for(int i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++)//选取到出发点距离最小的边
        {
            if(visit[j] == false && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++)//依次遍历每条要加入集合的边的相邻边
        {
            if(visit[v] == false && e[u][v] != inf){
                if(dis[u] + e[u][v] < dis[v]){
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }else if(dis[u] + e[u][v] == dis[v]){
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
        
    }
    

    printf("%d %d", num[c2], w[c2]);
    return 0;
}