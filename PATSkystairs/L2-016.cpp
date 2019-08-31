#include <cstdio>
#include <iostream>

using namespace std;

struct peo
{
    char gender;
    int f = -1, m = -1;
} p[100100];

bool judge(int a, int b, int d)
{
    if (a == -1 || b == -1)
        return true;
    if ((p[a].f != -1 && p[a].f == p[b].f) || (p[b].m != -1&& p[a].m == p[b].m))
        return false;
        
    d--;
    if (d <= 1)
        return true;
    return judge(p[a].f, p[b].f, d)&&judge(p[a].m, p[b].m, d)
    &&judge(p[a].f, p[b].m, d) && judge(p[a].m, p[b].f, d);
}

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        scanf(" %c%d%d", &p[id].gender, &p[id].f, &p[id].m);
        p[p[id].f].gender = 'M';
        p[p[id].m].gender = 'F';
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        if (p[a].gender == p[b].gender)
            printf("Never Mind\n");
        else
            printf("%s", judge(a, b, 5) == true ? "Yes\n" : "No\n");
    }

    return 0;
}