#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char c;
    int g = 0, p = 0, l = 0, t = 0;
    while (scanf("%c", &c) == 1 && c != '\n')
    {
        if (c == 'G' || c == 'g')
            g++;
        if (c == 'P' || c == 'p')
            p++;
        if (c == 'L' || c == 'l')
            l++;
        if (c == 'T' || c == 't')
            t++;
    }
    //printf("%d %d %d %d", g, p, l,t);
    while (g + p + l + t != 0)
    {
        if (g > 0)
        {
            printf("G");
            g--;
        }
        if (p > 0)
        {
            printf("P");
            p--;
        }
        if (l > 0)
        {
            printf("L");
            l--;
        }
        if (t > 0)
        {
            printf("T");
            t--;
        }
    }

    return 0;
}
