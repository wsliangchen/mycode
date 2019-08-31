#include <bits/stdc++.h>
using namespace std;

double dp[110][1020];

double dfs(int p, int q) {
    if (q >= 1000)
        return 100.0 / p;
    if (dp[p][q] != -1)
        return dp[p][q]; //返回dp最后结果
    dp[p][q] = 1.0 + (p / 100.0) * (1.0 - q / 1000.0) * dfs(p, q + 20) +
               (100.0 - p) / 100.0 * dfs(p, q + 15);
    return dp[p][q];
}

int main(int argc, char const *argv[]) {
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 1000; j++)
            dp[i][j] = -1;

    int caset = 1, t, p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &p);
        printf("Case %d: %.10f\n", caset++, dfs(p, 20));
    }

    return 0;
}