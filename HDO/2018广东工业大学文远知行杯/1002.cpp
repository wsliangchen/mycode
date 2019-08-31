#include <cstdio>

using namespace std;

int main()
{
    int n, m, T;
    scanf("%d", &T);
    while (T != 0)
    {
        scanf("%d%d", &n, &m);
        int arr[n];
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]), arr[i] += arr[i - 1];

        int t, L, R;

        while (m != 0)
        {//%50加或减期望不变
            scanf("%d%d%d", &t, &L, &R);
            if (t == 2)
                printf("%d\n", arr[R] - arr[L - 1]);
            m--;
        }
        T--;
    }

    return 0;
}