#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 100

struct graph
{
    int u, v, cost;
    void set(int a,int b,int w){
        u = a;
        v = b;
        cost = w;
    }
};

graph d[N * (N + 1) / 2];//有向图有N个顶点的图  边的数量e<= n(n+1)/2

//定义并查集
int father[N];
int Find(int x)
{
    if (father[x] == -1)
        return x;
    return father[x] = Find(father[x]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y) //同一个祖先
        return false;
    if (x > y)//不同祖先进行集合合并
        father[x] = y;
    if (x < y)
        father[y] = x;
    return true;
}

int cmp(graph x, graph y)
{
    return x.cost < y.cost;
}

int main(int argc, char const *argv[])
{
    int n, m;//n个顶点m条边

    FILE *fp = fopen("kruskal.in", "r");
    //读取边表
    while(fscanf(fp,"%d%d", &n,&m) != EOF && n != 0){
        int i;
        int v1, v2, w;
        for(int i = 0; i < m; i++)
        {
            fscanf(fp, "%d%d%d", &v1, &v2, &w);
            d[i].set(v1, v2, w);
        }
        sort(d, d + m, cmp);
        memset(father, -1, sizeof(father));//并查集初始化
        int sum = 0;//最小生成树边权的和
        int count = 0;//已经找到的边数
        //查找边
        for(int i = 0; i < n*(n+1)/2; i++)
        {
            if (Union(d[i].u, d[i].v)) {//找到不同集合的两条边
                printf("%d %d\n", d[i].u, d[i].v);
                sum += d[i].cost;
                count++;
            }
            if (count == n-1) {//n个顶点点都在同一集合内时构建完成
                break;
            }
        }
        printf("%d\n",sum);
    }
    getchar();
    return 0;
}