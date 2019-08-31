#include <cstdio>
#include <iostream>
#include <set>

using namespace std;
//辗转相除求最大公约数
int cal_gcd(int a, int b)
{
    int r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++)
    {
        set<int> s;
        for(int j = 1; j <= 1000; j++)
        {
            int gcd = cal_gcd(j, arr[i]);
            s.insert(gcd);
        }
        printf("%d\n", s.size());
    }
    return 0;
}