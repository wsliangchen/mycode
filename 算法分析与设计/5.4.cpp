#include <cstdio>
#include <iostream>

using namespace std;

//辗转相除法求最小公倍数
int gcd(int m,int n){
    return n == 0 ? m : gcd(n, m % n);
}

//最小公约数
int lcm(int m, int n){
    return (m * n) / gcd(m, n);
}

int main(int argc, char const *argv[])
{
    int m = 15, n = 3;
    printf("%d and %d lcm = %d", m, n, lcm(m,n));
    return 0;
}