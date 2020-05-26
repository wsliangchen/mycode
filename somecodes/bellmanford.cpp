#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
// acwing853有边数限制的最短路
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge {
    int a, b, w;
} edge[M];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; 
    for (int i = 0; i < k; i++) {
        memcpy(backup,dist,sizeof dist); //避免串联
        for (int j = 0; j < m; j++) {//松弛
            int a = edge[j].a,b = edge[j].b,w = edge[j].w;
            dist[b] = min(dist[b],backup[a]+w);
        }
    }
    if(dist[n] > 0x3f3f3f3f/2) return -1;
    return dist[n];
}

int main(int argc, char const *argv[]) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
    }

    int ans = bellman_ford();
    if(ans == -1) printf("impossible");
    else printf("%d", ans);
    return 0;
}