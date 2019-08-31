#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 1e5+10;

int main(int argc, char const *argv[])
{
    int n,d,cnt = 0, num[maxn];
    scanf("%d%d", &n, &d);
    do{
        num[cnt++] = n%d;
        n /= d;
    }while(n);
    bool judge = true;
    for(int i = 0; i < cnt/2; i++)
    {
        if(num[i] != num[cnt-i-1]) judge = false;
    }
    printf("%s\n", judge == true?"Yes":"No");
    for(int i = cnt - 1; i >= 0; i--)
    {
        printf("%s%d", i == cnt-1?"":" ", num[i]);
    }
    
    return 0;
}