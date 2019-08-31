#include <cstdio>
#include <cmath>
/**“如果把自我比作一根绳子，把现实比作一面无限长的笔直的墙，那么这个绳子和这个墙所能围成的最大面积就是那个人的全部。”
 * 如果把人比作一根长度为n的绳子，那么这根绳子和墙所能围成的最大面积是多少呢？
 */
using namespace std;

int main(int argc, char const *argv[])
{
    const double pi = acos(-1.0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int perimeter;
        scanf("%d", &perimeter);
        if (perimeter <= 0)
            printf("Impossble\n");
        else
            printf("%.8lf\n", perimeter * perimeter / (2 * pi));
    }
    return 0;
}