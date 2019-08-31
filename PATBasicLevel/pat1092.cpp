#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    int res[n+1] = {0};
    int max = -1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            res[j] += temp;
            if (res[j] > max) {
                max = res[j];
            }
        }
    }

    printf("%d\n", max);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if (res[i] == max) {
            printf("%s%d", cnt != 0?" ":"", i+1);
            cnt++;
        }
    }

    return 0;
}