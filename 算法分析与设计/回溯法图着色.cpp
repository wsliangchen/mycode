#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define NUM 100
int n,m,a[NUM][NUM],x[NUM],sum = 0;

//相邻色检验函数
bool Same(int t){
    for(int i = 1; i <= n; i++)
        if(a[t][i] == 1 && x[i] == x[t]) return false;
    return true;
}
//t为回溯深度
void BackTrack(int t){
    if(t > n){//填充完n个节点就输出并结束该分支
        sum++;
        for(int i = 1; i <= n; i++) 
            printf("%d%s", x[i], i == n?"\n":"");
    }else{
        for(int i = 1; i <= m; i++)
        {
            x[t] = i;
            if(Same(t)) BackTrack(t+1);
            x[t] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("mColoring1.in", "r", stdin);
    scanf("%d%d", &n, &m);//n节点数 m给定色数
    memset(a,0,sizeof(a));
    int b,e;
    while(scanf("%d%d", &b, &e) && (b || e)){
        a[b][e] = a[e][b] = 1;
    }
    BackTrack(1);
    printf("Total = %d\n", sum);
    return 0;
}