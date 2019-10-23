#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
//f（n）=f（n-1）+4*（n-1）+1
int main(int argc, char const *argv[])
{
    int n, a, f[10100];
    f[0] = 0, f[1] = 2, f[2] = 7;
    for(int i = 3; i <= 10000; i++)
        f[i] = f[i-1] + 4*(i-1) +1;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        printf("%d\n", f[a]);
    }
    return 0;
}