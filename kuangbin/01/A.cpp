#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, k, ans;
char plat[10][10];
int vi[10];

void dfs(int x, int t) { // x为行数，t为已经放的数量
    if (t == k) {
        ans++;
        return;
    }
    for (int i = x; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (plat[i][j] == '#' && vi[j] == 0) {
                vi[j] = 1;
                dfs(i + 1, t + 1);
                vi[j] = 0; //回溯
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    while (scanf("%d%d", &n, &k) && n != -1 && k != -1) {
        memset(plat, 0, sizeof(plat));
        memset(vi, 0, sizeof(vi));
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf("%s", plat[i]);
        dfs(0, 0);
        printf("%d\n", ans);
    }

    return 0;
}