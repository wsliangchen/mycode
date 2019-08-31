#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int arr[100010] = {0};
    for(int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    
    return 0;
}