#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const* argv[])
{
    map<int, double, greater<int>> a, b, ans;
    int n;
    for (int k = 0; k < 2; k++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int t1;
            double t2;
            scanf("%d%lf", &t1, &t2);
            if(k) b[t1] = t2;
            else a[t1] = t2;
        }
    }

    for (auto&& i : a) {
        for (auto&& j : b) {
            ans[i.first + j.first] += i.second * j.second;
        }
    }
   
    printf("%d", ans.size());
    for (auto&& i : ans) {
        printf(" %d %.1f", i.first, i.second);
    }

    return 0;
}