#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
//f(n) = f(n-1) + f(n+3)
using namespace std;

int main(int argc, char const *argv[])
{
    int f[100],n = -1;
    f[0] = 1,f[1] = 2,f[2] = 3,f[3] = 4;
    for(int i = 4; i < 60; i++)
        f[i] = f[i-3] + f[i-1];
    while(1){
        scanf("%d", &n);
        if(!n) break;
        printf("%d\n", f[n-1]);
    }

    return 0;
}