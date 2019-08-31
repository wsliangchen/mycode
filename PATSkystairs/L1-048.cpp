#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int ra, ca, rb, cb;
    cin >> ra >> ca;
    int a[ra][ca];

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
            cin >> a[i][j];
    }
    cin >> rb >> cb;
    int b[rb][cb];
    for (int i = 0; i < rb; i++)
    {
        for (int j = 0; j < cb; j++)
            cin >> b[i][j];
    }

    if (ca != rb)
    {
        printf("Error: %d != %d", ca, rb);
        return 0;
    }
    int res[ra][cb];
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            int sum = 0;
            for (int k = 0; k < ca; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
        }
    }
    printf("%d %d\n", ra, cb);
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            printf("%s%d", j == 0 ? "" : " ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
