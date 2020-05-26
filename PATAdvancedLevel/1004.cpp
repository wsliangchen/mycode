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

vector<int> v[110];

int leaves[110], maxdepth = 0;

void dfs(int depth, int id) {
    maxdepth = max(depth, maxdepth);
    if (v[id].size() == 0)
        return;
    for (int i = 0; i < v[id].size(); i++) {
        int child = v[id][i];
        if (v[child].size() == 0) {
            leaves[depth]++;
            continue;
        }
        dfs(depth + 1, child);
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int id, k, t;
        scanf("%d%d", &id, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &t);
            v[id].push_back(t);
        }
    }
    v[0].push_back(1);
    dfs(0, 0);
    for (int i = 0; i <= maxdepth; i++)
        printf("%s%d", i==0?"":" ",leaves[i]);

    return 0;
}