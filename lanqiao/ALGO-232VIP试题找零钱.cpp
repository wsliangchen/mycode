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
int m[110];
int main(int argc, char const *argv[]){
    int n;
    bool f = true;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if(t == 25)
            m[t]++;
        if(t == 50){
            if(m[25] != 0) m[25]--,m[50]++;
            else f = false;
        }
        if(t == 100){
            m[100]++;
            if(m[50] != 0 && m[25] != 0) m[50]--,m[25]--;
            else if(m[25] >= 3) m[25] -= 3;
            else f = false;
        }
    }
    printf("%s", f?"YES":"NO");
    return 0;
}