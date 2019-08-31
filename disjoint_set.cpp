#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 1e6 + 7;

int fa[maxn];

int fi(int x)
{
    return fa[x] == x ? x : fa[x] = fi(fa[x]);
}

void uni(int x, int y)
{
    int f1 = fi(x), f2 = fi(y);
    if (f1 == f2)
        return;
    fa[f1] = f2;
}

bool check(int x, int y)
{
    int f1 = fi(x), f2 = fi(y);
    if (f1 == f2)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    for(int i = 0; i < maxn; i++)//并查集初始化
        fa[i] = i;
    
    int n,k,q,peo = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        int arr[k];
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &arr[j]);
            if (arr[j] > peo)
                peo = arr[j];
        }
        if (k > 1) {
            for(int j = 0; j < k-1; j++)
                uni(arr[j], arr[j + 1]);
        }
    }
    set<int> s;
    for(int i = 1; i <= peo; i++)//统计部落数量
    {
        s.insert(fi(i));
    }
    
    scanf("%d", &q);
    printf("%d %d\n", peo, s.size());
    for(int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%s\n", check(a,b) == true?"Y":"N");
    }
    
    return 0;
}