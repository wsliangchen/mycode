#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct stu
{
    char id[20];
    int score;
};

struct kc
{
    int id;
    int pnum;
};

bool cmp(kc a, kc b)
{
    if (a.pnum != b.pnum)
        return a.pnum > b.pnum;
    else
        return a.id < b.id;
}
bool cmpstr(stu a, stu b)
{
    return strcmp(a,b) > 0;
}
int main(int argc, char const *argv[])
{
    int n, m, sumcnt = 0;

    scanf("%d%d", &n, &m);
    vector<stu> v;

    for (int i = 0; i < n; i++)
    {
        stu u;
        scanf("%s%d", u.id, &u.score);
        v.push_back(u);
        sumcnt += u.score;
    }
    sort(v.begin(), v.end(), cmpstr);

    for (int i = 0; i < m; i++)
    {
        int op;
        scanf("%d", &op);

        printf("Case %d: ", i + 1);
        if (op == 1)
        {
            char c;
            int acnt = 0;
            scanf(" %c", &c);
            printf("%d %c\n", op, c);
            for (int j = 0; j < n; j++)
            {
                if (v[j].id[0] == c)
                {
                    printf("%s %d\n", v[j].id, v[j].score);
                    acnt++;
                }
            }
            if (acnt == 0)
                printf("NA\n");
        }
        else if (op == 2)
        {

            char str[5];
            int bcnt = 0, bsum = 0;
            scanf("%s", str);
            printf("%d %s\n", op, str);
            for (int j = 0; j < n; j++)
            {
                bool same = true;
                for (int k = 1; k < 4; k++)
                {
                    if (str[k - 1] != v[j].id[k])
                    {
                        same = false;
                        break;
                    }
                }

                if (same)
                {
                    bcnt++;
                    bsum += v[j].score;
                }
            }
            if (bcnt == 0 && bsum == 0)
                printf("NA\n");
            else
                printf("%d %d\n", bcnt, bsum);
        }
        else if (op == 3)
        {
            char str[8];
            scanf("%s", str);
            printf("%d %s\n", op, str);
            vector<kc> k;
            map<int, int> mp;
            for (int j = 0; j < n; j++)
            {
                bool same = true;
                for (int k = 0; k < 6; i++)
                {
                    if (str[k] != v[j].id[k + 4])
                    {
                        same = false;
                        break;
                    }
                }
                if (same)
                {
                    int site = (v[j].id[1] - '0') * 100 + (v[j].id[2] - '0') * 100 + (v[j].id[3] - '0');
                    mp[site]++;
                }
            }
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                kc temp;
                temp.id = it->first;
                temp.pnum = it->second;
                k.push_back(temp);
            }
            sort(k.begin(), k.end(), cmp);
            if (k.size() == 0)
                printf("NA\n");
            else
            {
                for (int j = 0; j < k.size(); j++)
                    printf("%d %d\n", k[j].id, k[j].pnum);
            }
        }
    }

    return 0;
}