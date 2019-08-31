#include <cmath>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main(int argc, char const* argv[])
{
    int n;
    while (scanf("%d", &n) == 1) {
        int a = 0, b = 0, c = 0, d = 0,ans = 0;
        char ch;
        getchar();
        for (int i = 0; i < n; i++) {
            scanf("%c", &ch);
            if (ch == 'a')
                a++;
            if (ch == 'v')
                b = b + a;
            if (ch == 'i')
                c = c + b;
            if (ch == 'n')
                d = d + c;
        }
        getchar();
        long long pd = 1;
        for(int i = 0; i < n; i++)
        {
            pd *= 4;
            long long te = gcd(d,pd);
            d /= te;
            pd /= te;
        }
        
        long long gd = gcd(d, pd);
        printf("%lld/%lld\n", d / gd, d == 0 ? 1 : (pd / gd));
    }
    return 0;
}