#include <cstdio>

//辗转相除求最大公约数
long cal_gcd(long a, long b)
{
    long r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

void print_fraction(long n, long d)
{
    if (d == 0)
    {
        printf("Inf");
        return;
    }

    int inegative = 1;
    if (n < 0)
    {
        n = -n;
        inegative *= -1;
    }
    if (d < 0)
    {
        d = -d;
        inegative *= -1;
    }

    long gcd = cal_gcd(n, d);//化简到最间形式
    n /= gcd;
    d /= gcd;

    if (inegative == -1)
        printf("(-");
    if (n / d && n % d)
        printf("%ld %ld/%ld", n / d, n % d, d); 
    else if (n % d)
        printf("%ld/%ld", n % d, d); 
    else
        printf("%ld", n / d); 
    if (inegative == -1)
        printf(")");
}

int main()
{
    long a1, b1, a2, b2;//两个最大int相乘结果会超除int范围，要用long
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

    char op[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++)
    {
        print_fraction(a1, b1);
        printf(" %c ", op[i]);
        print_fraction(a2, b2);
        printf(" = ");
        switch (op[i])
        {
        case '+':
            print_fraction(a1 * b2 + a2 * b1, b1 * b2);
            break;
        case '-':
            print_fraction(a1 * b2 - a2 * b1, b1 * b2);
            break;
        case '*':
            print_fraction(a1 * a2, b1 * b2);
            break;
        case '/':
            print_fraction(a1 * b2, b1 * a2);
            break;
        }
        printf("\n");
    }

    return 0;
}
