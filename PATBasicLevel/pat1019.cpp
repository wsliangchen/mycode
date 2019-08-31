#include <cstdio>
#include <algorithm>

using namespace std;


int a[4] = {0};

int fun(int n, int* maxx, int *minn)
{
    for(int i = 0; i < 4; i++)
    {
        a[i] = n % 10;
        n /= 10;
    }
    sort(a, a+ 4);
    *maxx = a[0] + a[1] * 10 + a[2] * 100 + a[3] * 1000;
    *minn = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
    return *maxx - *minn;
}

int main()
{
    int maxx, minn;
    int *pmaxx = &maxx;
    int n;
    scanf("%d", &n);
    if(fun(n, &maxx, &minn) == 0)
    {
        printf("%04d - %04d = %04d\n", maxx, minn, maxx - minn);
    }
    else
    {
        while(1)
        {
            printf("%04d - %04d = %04d\n", maxx, minn, maxx - minn);
            if (maxx - minn == 6174)
                break;
            fun(maxx - minn);
        }
    }
    return 0;
}
