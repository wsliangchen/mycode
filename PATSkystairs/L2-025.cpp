#include <cstdio>
#include <cstring>
#include <list>
#include <vector>
using namespace std;

const int maxn = 10010;

vector<int> mat[maxn];
int dt[maxn];
int main(int argc, char const *argv[]) {
    int n, m, np, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int ck;
    scanf("%d", &ck);
    while (ck--) {
        memset(dt, 0, sizeof dt);
        scanf("%d", &np);
        while (np--) {
            scanf("%d", &a);
            dt[a] = 1;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
            for(auto t : mat[i]){
                if(dt[i] == 0 && dt[t] == 0){
                    flag = false;
                    break;
                }
            }
        }
        printf("%s\n", flag?"YES":"NO");
    }
    return 0;
}