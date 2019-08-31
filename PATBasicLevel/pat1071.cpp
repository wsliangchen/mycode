#include <stdio.h>

bool isWin(int n1, int b, int t, int n2)
{
    return (b == (n2 > n1 ? 1 : 0)) ? true : false;
}

int main(int argc, char const *argv[])
{
    int T, K, n1, b, t, n2, i;
    scanf("%d %d", &T, &K);

    for (i = 0; i < K; i++)
    {
        scanf("%d%d%d%d", &n1, &b, &t, &n2);
        if (T <= 0)
        {
            printf("Game Over.\n");
            return 0;
        }
        if (T < t)
            printf("Not enough tokens.  Total = %d.\n", T);
        else
        {
            if (isWin(n1, b, t, n2) == true)
            {
                T += t;//注意输出的时候Total前面是两个空格
                printf("Win %d!  Total = %d.\n", t, T);
            }
            else
            {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            }
        }
    }
    return 0;
}