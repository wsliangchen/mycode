#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;
    char a[63], b[63], c[63], d[63];
    scanf("%s%s%s%s",a,  b, c, d);
    char days[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int day, hour, minute;
    int abminlen = (strlen(a)> strlen(b)) ? strlen(b) : strlen(a);
    for (int i = 0; i<abminlen; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] >= 'A' && a[i] <= 'G' && count == 0)
            {
                day = a[i] - 'A';
                count++;
            }
            else if (count > 0 && ((a[i]>='A' && a[i] <= 'N')||isdigit(a[i])))
            {
                if (isdigit(a[i]))
                    hour = a[i] - '0';
                else
                    hour = a[i] - 'A' + 10;
                break;
            }
        }
    }
    int cdminlen = strlen(c)> strlen(d) ? strlen(d) : strlen(c);
    for (int i = 0; i<cdminlen; i++)
    {
        if (c[i] == d[i] && isalpha(c[i]))
        {
            minute = i;
            break;
        }
    }
    printf("%s %02d:%02d", days[day], hour, minute);
    return 0;
}
