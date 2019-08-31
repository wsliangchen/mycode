#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = n; i > 0; i--)
    {
        for(int j = i; j > 0; j--)
        {
            printf("%s*", j==i?"":" ");
        }
        printf("\n");
    }
    
    return 0;
}