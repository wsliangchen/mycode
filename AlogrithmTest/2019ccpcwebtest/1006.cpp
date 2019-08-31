#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

struct tb {
    int v, no;
}t[100010];

bool cmp(tb a, tb b){
    return a.no<b.no;
}

unordered_map<int,int> mp;
int main(int argc, char const *argv[]) { 
    int n,m, mt = -1;
    scanf("%d%d", &n,&m);
    for(int i = 0; i < n; i++){
        scanf("%d", &t[i].v);
        t[i].no = i;
        mp[t[i].v] = i;
    }
    for(int i = 0; i < m; i++)
    {
        int sq,index;
        scanf("%d", &sq);
        index = mp[sq];
        t[index].no = mt;
        --mt;
    }
    sort(t,t+n, cmp);
    int i= 0;
    for(; i < n-1; i++){
        printf("%d ", t[i].v);
    }
    printf("%d ", t[i]);
    return 0; 
}