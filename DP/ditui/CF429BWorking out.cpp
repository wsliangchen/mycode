#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int mp[1010][1010];
int dp1[1010][1010],dp2[1010][1010],dp3[1010][1010],dp4[1010][1010];
int main(int argc, char const *argv[])
{
    int n,m;
    while(scanf("%d%d", &n,&m) == 2){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &mp[i][j]);
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(dp3, 0, sizeof(dp3));
        memset(dp4, 0, sizeof(dp4));
        for(int i = 1; i <= n; i++)//右下
            for(int j = 1; j <= m; j++)
                dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + mp[i][j];
        for(int i = n; i >= 1; i--)//右上
            for(int j = 1; j <= m; j++)
                dp2[i][j] = max(dp2[i+1][j], dp2[i][j-1]) + mp[i][j];
        for(int i = 1; i <= n; i++)//左下
            for(int j = m; j >= 1; j--)
                dp3[i][j] = max(dp3[i-1][j], dp3[i][j+1]) + mp[i][j];
        for(int i = n; i >= 1; i--)//左上
            for(int j = m; j >= 1; j--)
                dp4[i][j] = max(dp4[i+1][j], dp4[i][j+1]) + mp[i][j];
        int ans=0;
        for(int i=2; i<n; i++)
            for(int j=2; j<m; j++)
            {
                ans=max(ans,dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j]);
                ans=max(ans,dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1]);
            }
        printf("%d\n",ans);
    }
    
    return 0;
}