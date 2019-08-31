#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdint>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int ans = 0;
    for(int i = 1; i <= 255; i++)
    {
        int t = floor(pow(i,1.0/3));
        ans += gcd(t,i);
    }
    printf("\n%d", ans);
    return 0;
}