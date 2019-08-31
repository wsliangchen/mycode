#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

struct people
{
    char name[10];
    int ts,diffs;
};

bool cmp(people a, people b)
{
    if (a.diffs == b.diffs) {
        return a.ts < b.ts;
    }
    return a.diffs > b.diffs;
}
int main()
{
    int n;
    scanf("%d", &n);
    unordered_set<int> s;
    people p[n];
    for(int i = 0; i < n; i++)
    {
        s.clear();
        scanf("%s%d",p[i].name, &p[i].ts);
        for(int j = 0; j < p[i].ts; j++)
        {
            int temp;
            scanf("%d", &temp);
            s.insert(temp);
        }
        p[i].diffs = s.size();
    }
    sort(p, p + n, cmp);
    for(int i = 0; i < 3; i++)
    {
        if (i > n-1) {
            printf("%s-", i==0?"":" ");
        }else
        {
            printf("%s%s",i==0?"":" ", p[i].name);
        }
        
    }
    

    return 0;
}
