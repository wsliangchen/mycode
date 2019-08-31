#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct people
{
    int income;
    int ts;
    int no;
};

bool cmp(people a, people b)
{
    if (a.income == b.income)
    {
        if (a.ts == b.ts)
            return a.no < b.no;
        else
            return a.ts > b.ts;
    }
    return a.income > b.income;
}

int main()
{
    int n, k, a, b;
    scanf("%d", &n);
    people p[n];
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        p[i].no = i + 1;
        for (int j = 0; j < k; j++)
        {
            scanf("%d%d", &a, &b);
            p[i].income -= b;
            p[a-1].income += b;
            p[a-1].ts++;
        }
    }

    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d %.2lf\n",p[i].no,  (double)(p[i].income*1.0/100));
    }

    return 0;
}
