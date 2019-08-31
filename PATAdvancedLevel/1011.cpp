#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    double res = 1;
    for(int i = 0; i < 3; i++)
    {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        if (a > b && a > c) {
            printf("W ");
            res *= a;
        }else if (b > a && b > c) {
            printf("T ");
            res *= b;
        }else if (c > a && c > b) {
            printf("L ");
            res *= c;
        }
    }
    printf("%.2lf", (res*0.65 - 1)*2 );

    return 0;
}