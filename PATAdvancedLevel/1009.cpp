#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
/*pat开始没过第一个用例，
原因是系数为零的项不用输出，
牛客的用例没有考虑到这一点*/
int main(int argc, char const *argv[]) {
    map<int, double, greater<int>> a, b, ans;
    int n;
    for (int k = 0; k < 2; k++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int t1;
            double t2;
            scanf("%d%lf", &t1, &t2);
            if (k)
                b[t1] = t2;
            else
                a[t1] = t2;
        }
    }

    for (auto &&i : a) {
        for (auto &&j : b) {
            ans[i.first + j.first] += i.second * j.second;
        }
    }

    printf("%d", ans.size());
    int j = 0;
    for (auto &&i : ans) {
        if (i.first != 0) {
            printf("%s%d %.1f", j == 0 ? "" : " " i.first, i.second);
            j++;
        }
    }

    return 0;
}