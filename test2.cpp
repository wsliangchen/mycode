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
    getchar();
    for(int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        if(c == 'G') ans++;
    }
    printf("%d", ans);
    
    return 0;
}