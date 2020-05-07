#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int K, N, R;
struct Road {
    int d, L, t;
};
vector<vector<Road>> cityMap(110);

int minLen = 1 << 30;
int totalLen;
int totalCost;
int visited[110];
int minL[110][10100];

void Dfs(int s) {
    if (s == N) {
        minLen = min(minLen, totalLen);
        return;
    }
    for (int i = 0; i < cityMap[s].size(); i++) {
        int d = cityMap[s][i].d;
        if (!visited[d]) {
            int cost = totalCost + cityMap[s][i].t;
            if (cost > K)
                continue;
            if (totalLen + cityMap[s][i].L >= minLen ||
                totalLen + cityMap[s][i].L >= minL[d][cost])
                continue;
            //改变状态
            minL[d][cost] = totalLen;
            totalLen += cityMap[s][i].L;
            totalCost += cityMap[s][i].t;
            visited[d] = 1;
            Dfs(d);
            //回溯恢复状态
            visited[d] = 0;
            totalLen += cityMap[s][i].L;
            totalCost += cityMap[s][i].t;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> K >> N >> R;
    for (int i = 0; i < R; i++) {
        int s;
        Road r;
        cin >> s >> r.d >> r.L >> r.t;
        if (s != r.d)
            cityMap[s].push_back(r);
    }
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 10100; j++)
            minL[i][j] = 1 << 30;

    visited[1] = 1;
    if(minLen < (1<<30))
        cout << minLen;
    else
        cout << "-1";
    return 0;
}