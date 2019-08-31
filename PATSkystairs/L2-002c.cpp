#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct Node
{
    int val;
    int next;
} a[100005];
int vis[100005];
int ans[100005], res[100005];

int main()
{
    int adress, n;
    scanf("%d%d", &adress, &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        scanf("%d%d", &a[temp].val, &a[temp].next);
    }
    int pos1 = 0;
    int pos2 = 0;
    for (int i = adress; i != -1; i = a[i].next)
    {
        int num = abs(a[i].val);
        if (!vis[num])
            vis[num] = 1, ans[pos1++] = i;
        else
            res[pos2++] = i;
    }
    printf("%05d %d ", ans[0], a[ans[0]].val);
    for (int i = 1; i < pos1; i++)
    {
        printf("%05d\n", ans[i]);
        printf("%05d %d ", ans[i], a[ans[i]].val);
    }
    printf("-1\n");
    if (pos2)
    {
        printf("%05d %d ", res[0], a[res[0]].val);
        for (int i = 1; i < pos2; i++)
        {
            printf("%05d\n", res[i]);
            printf("%05d %d ", res[i], a[res[i]].val);
        }
        printf("-1\n");
    }
}
