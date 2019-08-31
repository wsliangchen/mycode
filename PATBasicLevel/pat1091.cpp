#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        int res = 0;
        for (int j = 1; j < 10; j++)
        {
            char a[10], b[10];
            sprintf(a, "%d", temp);
            sprintf(b, "%d", j * temp * temp);
            int k, l;
            for (k = strlen(a) - 1, l = strlen(b) - 1; k >= 0; k--, l--)
            {
                if (a[k] != b[l])
                    break;
            }
            if (k == -1)
            {
                res = j;
                break;
            }
        }
        if (res != 0)
            printf("%d %d\n", res, res * temp * temp);
        else
            printf("No\n");
    }
    return 0;
}