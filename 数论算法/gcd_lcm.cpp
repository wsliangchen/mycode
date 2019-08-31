#include <cstdio>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    printf("a = %d, b = %d\n", a,b);
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);

    int res = gcd(a, b);
    //printf("gcd = %d\n", res);
    printf("lcm = %d\n", a*b/gcd(a,b));
    return 0;
}