#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[10005];
    memset(arr, 0, sizeof(arr));
    int n;
    scanf("%d", &n);
    int res[n];
    for(int i = 0,p = 0; i < n; i++,p++)
    {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
        res[p] = temp;
    }

    bool b = false;
    for(int i = 0; i < n; i++)
    {
        if (arr[res[i]] == 1) {
            printf("%d", res[i]);
            b = true;
            break;
        }
    }
    printf("%s", b?"":"None");
    return 0;
}