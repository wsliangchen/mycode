#include <cstdio>
using namespace std;

struct data
{
    int exp;
    double coef;
};

int main(int argc, char const *argv[])
{
    int acnt, bcnt;
    scanf("%d", &acnt);
    data a[acnt];
    for (int i = 0; i < acnt; i++)
        scanf("%d%lf", &a[i].exp, &a[i].coef);
    scanf("%d", &bcnt);
    data b[bcnt];
    for (int i = 0; i < bcnt; i++)
        scanf("%d%lf", &b[i].exp, &b[i].coef);

    data res[acnt + bcnt];
    int rcnt = 0, i = 0, j = 0;

    while (i < acnt || j < bcnt)
    {
        if (i >= acnt && j < bcnt)
        {
            res[rcnt] = b[j];
            j++;
        }
        else if (i < acnt && j >= bcnt)
        {
            res[rcnt] = a[i];
            i++;
        }
        else
        {
            if (a[i].exp > b[j].exp)
            {
                res[rcnt] = a[i];
                i++;
            }
            else if (a[i].exp < b[j].exp)
            {
                res[rcnt] = b[j];
                j++;
            }
            else if (a[i].exp == b[j].exp)
            {
                if (a[i].coef + b[j].coef != 0)
                {
                    res[rcnt].exp = a[i].exp;
                    res[rcnt].coef = a[i].coef + b[j].coef;
                    i++;
                    j++;
                }else
                {
                    i++;
                    j++;
                    continue;
                }
            }
        }

        rcnt++;
    }

    printf("%d", rcnt);
    for (int k = 0; k < rcnt; k++)
        printf("%s%d %.1lf", " ", res[k].exp, res[k].coef);

    return 0;
}