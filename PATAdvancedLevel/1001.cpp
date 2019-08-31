#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);

    char temp[100], res[100];
    sprintf(res, "%d", a + b);
    int j = 0,k = 0;
    for(int i = strlen(res)-1; i >= 0; i--)
    {
        if (k%3 == 0 && i != strlen(res)-1 && res[i] != '-') {
            temp[j++] = ',';
        }
        k++;
        temp[j++] = res[i];
    }
    temp[j] = '\0';

    for(int i = strlen(temp)-1; i >= 0; i--)
    {
        printf("%c", temp[i]);
    }

    return 0;
}