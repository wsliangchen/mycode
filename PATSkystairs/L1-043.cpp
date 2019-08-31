#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int day = n;
    int bookid[2010];
    memset(bookid, -1, sizeof(bookid));
    int bnum = 0, rnum = 0;
    while (day > 0)
    {
        int id, h, m;
        char op;
        scanf("%d %c %d:%d", &id, &op, &h, &m);

        if (id == 0)
        {
            day--;
            memset(bookid, -1, sizeof(bookid));
            printf("%d %.lf\n", bnum, bnum == 0?0:((1.0*rnum+0.5f)/bnum));
            bnum = 0;
            rnum = 0;
            continue;
        }
        if ((op == 'E' && bookid[id] == -1) || 
        op == 'S' && bookid[id] != -1)
            continue;
        if (op == 'S') {
            bookid[id] = h * 60 + m;
        }
        if (op == 'E') {
            rnum += h * 60 + m - bookid[id];
            bookid[id] = -1;
            bnum++;
        }
    }

    return 0;
}
