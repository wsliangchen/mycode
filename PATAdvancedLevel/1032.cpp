#include <bits/stdc++.h>

using namespace std;

int vis[100010];
int path[100010];

int main(int argc, char const *argv[]){
    int as,bs,t;
    scanf("%d%d%d", &as, &bs, &t);
    while(t--){
        int a,b;
        scanf("%d%*s%d", &a, &b);
        path[a] = b;
    }

    while(as != -1){
        vis[as]++;
        as = path[as];
    }
    bool flag = true;
    int ans = -1;
    while(bs != -1){
        vis[bs]++;
        if(vis[bs] == 2 && flag) flag = false, ans = bs;
        bs = path[bs];
    }
    if(ans == -1) printf("-1");
    else printf("%05d", ans);
    return 0;
}