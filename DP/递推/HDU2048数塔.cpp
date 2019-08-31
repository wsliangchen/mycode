#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int dp[110][110];

int main(int argc, char const *argv[])
{
    int c,n,ans;

    scanf("%d", &c);
    while(c--){
        memset(dp,0,110*110);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                scanf("%d", &dp[i][j]);
        }

        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++){
                if(j == 1)
                    dp[i][j] = dp[i][j] + dp[i-1][j];
                else if(j == i)
                    dp[i][j] = dp[i][j] + dp[i-1][j-1];
                else{
                    dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
            ans = dp[n][i] > ans?dp[n][i]:ans;
        printf("%d\n", ans);
    }

    return 0;
}