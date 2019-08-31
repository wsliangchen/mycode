#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    long long arr[1000];
    int  n, a,b;
    arr[0] = 0, arr[1] = 1;
    for(int i = 2; i < 200; i++)
        arr[i] = arr[i-1] + arr[i-2];
    scanf("%d", &n);

    while(n--){
        scanf("%d%d", &a, &b);
        printf("%lld\n", arr[b-a+1]);
    }

    return 0;
}