#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int main(int argc, char const *argv[]){
    int n,ans = 0;
    scanf("%d", &n);
    char s[15];
    for(int i = 1; i <= n; i++)
    {
        sprintf(s,"%d",i);
        for(int j = 0; j < strlen(s); j++)
            if(s[j] == '1') ans++;
    }
    printf("%d", ans);
    return 0;
}