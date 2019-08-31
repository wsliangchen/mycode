#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n == 1 || n == 2)
        return true;

    for(int i = 2; i < sqrt(n)+1; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d%d", &n, &k);
    char str[n + 5];
    scanf("%s", str);

    for(int i = 0; i < strlen(str)-k+1; i++)
    {
        char temp[12];
        strncpy(temp, str+i, k);
        //temp[k] = '/0';
        int p;
        sscanf(temp, "%d", &p);
        char bit[12];
        sprintf(bit, "%d", p);
        if (is_prime(p) && p != 0) {
            int zero = k - strlen(bit);
            for(int j = 0; j < zero; j++)
                printf("0");
            printf("%d", p);
            return 0;
        }
    }
    printf("404");
    return 0;
}