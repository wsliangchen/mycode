#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int m, n, s, count = 0;
    scanf("%d%d%d", &m, &n, &s);
    int i, j;
    char name[m + 1][21];
    int wintime[m + 1];
    for (i = 1; i <= m; i++)
    {
        scanf("%s", name[i]);
        wintime[i] = 0;
    }
        
    for (int i = s; i <= m;)
    {
        bool flag = true;
        for (int j = 1; j <= m; j++)
        {
            if (strcmp(name[i], name[j]) == 0 && wintime[j] != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            wintime[i]++;
            count++;
            i += n;
        }
        else
            i++;
    }
    if (count == 0)
        printf("Keep going...");
    else
    {
        for (int i = 1; i <= m; i++)
        {
            if (wintime[i] != 0)
                printf("%s\n", name[i]);
        }
    }
    return 0;
}
