#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int cnt = 0, floor = 0;
    for(int i = 0; i < n; i++)
    {
        int nextf;
        scanf("%d", &nextf);

        if (nextf > floor) 
            cnt += (nextf - floor) * 6;
        else
            cnt += (floor - nextf) * 4;
        cnt += 5;
        floor = nextf;
    }
    printf("%d", cnt);

    return 0;
}