#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    //printf("a = %d, b = %d\n", a,b);
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    //int a = 70044, b = 113148;
    //scanf("%d%d", &a, &b);

    //int res = gcd(a, b);
    printf("gcd = %d\n", __gcd(70044,113148));
    //printf("lcm = %d\n", a*b/gcd(a,b));
    return 0;
}