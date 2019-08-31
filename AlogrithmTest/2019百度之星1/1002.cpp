#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int t;
    scanf("%d", &t);
    while (t--) {
        vector<int> v;
        int a, b, maxn = -999999999, minn = 999999999, n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            v.push_back(a);
            v.push_back(b);
            maxn = max(b, maxn);
            minn = min(a, minn);
        }

        int maxt = -999999999, mint = 999999999;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > maxt && v[i] != maxn)
                maxt = v[i];
            if (v[i] < mint && v[i] != minn)
                mint = v[i];
        }
        printf("min = %d max = %d\n", mint, maxt);
        if(mint == maxt){
            printf("0\n");
            continue;
        }
        if()
    }

    return 0;
}