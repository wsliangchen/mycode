#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    long long n, suma = 0, sumb = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long a, b, gcdv;
        scanf("%lld/%lld", &a, &b);
        gcdv = (suma == 0 || sumb == 0) ?1:gcd(abs(suma), abs(sumb));
        sumb /= gcdv;
        suma /= gcdv;
        gcdv = (a == 0 || b == 0) ? 1 : gcd(abs(a), abs(b));
        a /= gcdv;
        b /= gcdv;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    long long gcdv= (suma == 0 || sumb == 0) ? 1:gcd(abs(suma), abs(sumb));
    suma /= gcdv;
    sumb /= gcdv;
    if (integer != 0)
        printf("%lld%s", integer,suma==0?"":" ");
    if (suma != 0) {
        printf("%lld/%lld", suma, sumb);
    }
    if (integer == 0 && suma == 0) {
        printf("0");
    }
    
    
    return 0;
}
