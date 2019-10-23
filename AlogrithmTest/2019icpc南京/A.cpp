#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

ll bg(ll n, ll i, ll j) {
    if (i == n)
        return n - j + 1;
    if (j == 1)
        return n + n - i;
    if (i == 1)
        return n * 2 - 2 + j;
    if (j == n)
        return 3 * n + i - 3; //以上就是如果当前的点就是最外层，直接返回
    return 4 * n - 4 + bg(n - 2, i - 1, j - 1);
}

int calvalue(ll n, ll x, ll y) {
    ll tep = bg(n, x, y);
    char s[50];
    int ans = 0;
    sprintf(s, "%lld", tep);
    for (int i = 0; s[i]; i++) {
        ans += s[i] - '0';
    }
    return ans;
}
ll sum(int &x1,int &y1,int &x2,int &y2, unordered_map<pair<int, int>, int> &mp){
    
}
int main(int argc, char const *argv[]) {

    int t;
    scanf("%d", &t);
    while (t--) {
        unordered_map<pair<int, int>, int> mp;
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[make_pair(x, y)] = calvalue(x, y);
        }
        for (int i = 0; i < p; i++) {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
        }
    }
    return 0;
}