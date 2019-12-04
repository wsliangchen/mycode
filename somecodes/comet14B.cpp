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
    int t;
    char str[1001000];
    scanf("%d", &t);
    while(t--){
        int p=-1,i=-1,n=-1,rk=-1,ri=-1,rn=-1;
        int len = 0;
        scanf("%d", &len);
        getchar();
        for(int j = 0; j < len; j++){
            scanf("%c", &str[j]);
            if(p == -1 && str[j] == 'p') p = j;
            if(i == -1 && p != -1 && str[j] == 'i') i = j;
            if(n == -1 && i != -1 && str[j] == 'n') n = j;
        }
        //printf("%d %d %d len = %d", p,i,n, len);
        getchar();
        for(int j = len-1; j>=p; j--){
            if(rk == -1 && str[j] == 'k') rk = j;
            if(rn == -1 && rk != -1 && str[j] == 'n') rn = j;
            if(ri == -1 && rn != -1 && str[j] == 'i'){ 
                ri = j;
                break;
            }
        }
        //printf("%d %d %d\n", ri ,rn, rk);
        int a=-1,b=-1, c=-1, ans = -1;
        if(ri != -1 && p != -1) a = ri-p;
        if(rn != -1 && i != -1) b = rn -i;
        if(rk != -1 && n != -1) c = rk -n;
        ans = max(max(a,b),max(b,c));
        printf("%d\n", ans==-1?ans:(ans-1));
    }
    return 0;
}