#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int u, x, y;
    scanf("%d %d %d", &u, &x, &y);

    int a, b;      //甲乙丙能力值
    double c = -1; //丙不一定为整数
    //从甲的最大解开始尝试
    for (a = 99; a >= 10; a--)
    {
        b = a / 10 + (a % 10) * 10; //乙的能力值
        c = (double)abs(a - b) / x;
        if (c * y == b)
        {
            printf("%d %s %s %s\n", a, u > a ? "Gai" : (u == a ? "Ping" : "Cong"),
                   u > b ? "Gai" : (u == b ? "Ping" : "Cong"), u > c ? "Gai" : (u == c ? "Ping" : "Cong"));
            return 0;
        }
    }
    printf("No Solution\n");

    return 0;
}