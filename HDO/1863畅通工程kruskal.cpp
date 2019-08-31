#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N  111

struct edge
{
    int from, to;
    long long cost;
}E[MAX_N*MAX_N];

int N, M;

int father[MAX_N];

//并查集初始化
void init(){
    for(int i = 1; i <= N; i++)
        father[i] = i;
}

//查找x所属的集合
int Find(int x){
    if (x == father[x])
        return x;
    return x==father[x]?x:father[x] = Find(father[x]);
}//return x == father[x] ? x : father[x] = Find(father[x]);

//查找xy是否属于同一个集合
bool Same(int x, int y){
    return Find(x) == Find(y);
}

//集合合并
void unionSet(int x,int y){
    int u = Find(x), v = Find(y);
    if(u == v)
        return;
    father[u] = v;
}

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

long long  Kruskal(){
    long long res = 0;
    sort(E + 1, E + 1 + M, cmp);
    for(int i = 1; i <= M; i++)
    {
        if (Same(E[i].from, E[i].to))
            continue;
        unionSet(E[i].from, E[i].to);
        res += E[i].cost;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    while(scanf("%d%d", &M, &N) == 2){
        if(M == 0)
            break;
        init();
        for(int i = 1; i <= M; i++)
            scanf("%d%d%lld", &E[i].from, &E[i].to, &E[i].cost);

        long long res = Kruskal();
        for(int i = 1; i <= N; i++)
        {
            if(!Same(i,1))
                res = -1;
        }
        if (res == -1)
            printf("?\n");
        else
            printf("%lld\n", res);

    }
    return 0;
}