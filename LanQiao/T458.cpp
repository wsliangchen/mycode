#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
const int maxn = 1e6 + 10;

int fa[maxn];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void uni(int x, int y)
{
    int f1 = find(x), f2 = find(y);
    if (f1 == f2)
        return;
    fa[f1] = f2;
}

bool check(int x, int y)
{
    int f1 = find(x), f2 = find(y);
    return f1 == f2;
}

int main(int argc, char const* argv[])
{
    for (int i = 0; i < maxn; i++) //并查集初始化
        fa[i] = i;
    int m,n,ans = 0,t;
    scanf("%d%d%d", &m, &n,&t);
    for(int i = 0; i < t; i++)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        if(!check(a,b)) uni(a,b);
    }
    
    for(int i = 1; i <= m*n; i++)
    {
        if(fa[i] == i) ans++;
    }
    printf("%d", ans);
    return 0;
}