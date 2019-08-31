#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%d", &n);
    if (n == 0) {
        printf("1");
        return 0;
    }
    
    int temp = n;
    for(int i = n-1; i > 0; i--,n--)
    {
        temp *= (n-1);
        while(temp%10 == 0)
            temp /= 10;
        temp %= 10;
    }
    
    printf("%d", temp);
    return 0;
}