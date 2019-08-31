#include <bits/stdc++.h>
using namespace std;

int vis[100010],t,b, ans = -1;

int main(int argc, char const *argv[]){
    scanf("%*d%*d%d",&t);
    while(t--){
        scanf("%*d%*s%d", &b);
        if(b == -1) continue;
        vis[b]++;
        if(vis[b] == 2) ans = b;
    }
    if(ans == -1) printf("-1");
    else printf("%05d", ans);
    return 0;
}