#include <cstdio>
#include <cstring>

using namespace std;
int main()
{
    int al, bl, ta, tb;
    scanf("%d%d", &al, &bl);
    ta = al;
    tb = bl;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a+c == b && a+c != d) {
            al--;
        }else if (a+c == d && a+c != b) {
            bl--;
        }
        if (al == -1 || bl == -1)
            break;
    }

    printf("%s\n%d", al==-1?"A":"B", al == -1?tb-bl:ta-al);

    return 0;
}
