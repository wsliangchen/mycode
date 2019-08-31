#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 5, p[5] = {0,1,2,3,4};
    sort(p, p + n);

    do
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
    } while (next_permutation(p, p+n));
    
    return 0;
}