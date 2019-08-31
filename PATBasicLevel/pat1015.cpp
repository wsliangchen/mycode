#include <stdio.h>
#include <algorithm>

using namespace std;
int n, l, h;

struct stu
{
    int id;
    int d; //德分
    int c; //才分
};
bool sameJudge(stu a, stu b);
bool dcJudge(stu a, stu b);
bool compare(stu a, stu b);

bool compare(stu a, stu b)
{
    if (a.c >= h && a.d >= h && b.c >= h && b.d >= h)
        return dcJudge(a, b);//第一类德才全尽
    else if (a.d >= h && b.d >= h)
        return dcJudge(a, b);//第二类德分够h才分不够h
    else if (a.d >= a.c && b.d >= b.c)
        return dcJudge(a, b);//第三类德才分都够l但不到h并且德分大于等于才分
    else
        return dcJudge(a, b);//第四类德才分够l不够h并且德分小于才分
}

bool dcJudge(stu a, stu b)
{
    if (a.d + a.c == b.d + b.c)
        return sameJudge(a, b);
    else
        return a.d + a.c > b.d + b.c;
}

//德才总分相等的情况下进行的判断
bool sameJudge(stu a, stu b)
{
    if (a.d != b.d)
        return a.d > b.d;
    else
        return a.id < b.id;
}

void storage(int id, int d, int c, stu *s)
{
    s->id = id;
    s->d = d;
    s->c = c;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &l, &h);
    stu a[n], b[n], c[n], d[n];
    int acount = 0, bcount = 0, ccount = 0, dcount = 0;
    for (int i = 0; i < n; i++)
    {
        int idtemp, dtemp, ctemp;
        scanf("%d%d%d", &idtemp, &dtemp, &ctemp);
        if (dtemp >= l && ctemp >= l)
        {
            if (dtemp >= h && ctemp >= h) //第一类德才全尽
                storage(idtemp, dtemp, ctemp, &a[acount++]);
            else if (dtemp >= h && dtemp > ctemp)//第二类德胜才
                storage(idtemp, dtemp, ctemp, &b[bcount++]);
            else if (dtemp >= ctemp)//第三类才德兼亡尚有德胜才德分大于等于h才分小于h
                storage(idtemp, dtemp, ctemp, &c[ccount++]);
            else //第四类德才分够l不够h
                storage(idtemp, dtemp, ctemp, &d[dcount++]);
        }
    }

    sort(a, a + acount, compare);
    sort(b, b + bcount, compare);
    sort(c, c + ccount, compare);
    sort(d, d + dcount, compare);
    printf("%d\n", acount+bcount+ccount+dcount);
    for (int i = 0; i < acount; i++)
        printf("%08d %d %d\n", a[i].id, a[i].d, a[i].c);
    for (int i = 0; i < bcount; i++)
        printf("%08d %d %d\n", b[i].id, b[i].d, b[i].c);
    for (int i = 0; i < ccount; i++)
        printf("%08d %d %d\n", c[i].id, c[i].d, c[i].c);
    for (int i = 0; i < dcount; i++)
        printf("%08d %d %d\n", d[i].id, d[i].d, d[i].c);

    return 0;
}
