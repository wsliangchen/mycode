#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int pre[1010];
vector<int> res;
bool isMirror;
void create(int l, int r)
{
    if (l > r)
        return;
    int tr = l + 1, tl = r;
    if (!isMirror)
    {
        while (tr <= r && pre[tr] < pre[l])
            tr++;
        while (tl > l && pre[tl] >= pre[l])
            tl--;
    }
    else
    {
        while (tr <= r && pre[tr] >= pre[l])
            tr++;
        while (tl > l && pre[tl] < pre[l])
            tl--;
    }
    if (tr - tl != 1)
        return;
    create(l + 1, tl);
    create(tr, r);
    res.push_back(pre[l]);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    create(0, n - 1);
    if (res.size() != n)
    {
        isMirror = 1;
        res.clear();
        create(0, n - 1);
    }
    if (res.size() != n)
    {
        printf("NO");
    }
    else
    {
        printf("YES\n");
        for (int j = 0; j < res.size(); j++)
            printf("%s%d", j == 0 ? "" : " ", res[j]);
    }

    return 0;
}