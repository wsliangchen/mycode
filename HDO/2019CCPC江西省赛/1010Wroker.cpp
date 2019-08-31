#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct wh {
    int no;
    int ai;
    int num;
};

bool cmp(wh a, wh b)
{
    return a.ai < b.ai;
}
bool cmp1(wh a, wh b)
{
    return a.no < b.no;
}
int main(int argc, char const* argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<wh> v;
        for (int i = 1; i <= n; i++) {
            int t;
            scanf("%d", &t);
            v.push_back(wh{ i, t, 0 });
        }
        sort(v.begin(), v.end(), cmp);
        int arr[n + 1];
        bool flag = false;//成功标记
        for (int i = 1; i <= m - n; i++) {//从最小的仓库开始分配
            int oneday = v[0].ai * i, j, tm = m-i;
            v[0].num = i;
            for (j = 1; j < n; j++) {
                if (oneday > v[j].ai && oneday % v[j].ai == 0 && tm > 0){
                    v[j].num = oneday / v[j].ai;
                    tm -= v[j].num;
                }
                else
                    break;
            }
            if (j == n) {//分配到最后一个仓库成功
                flag = true;
                if(j == 1){
                    printf("Yes\n%d\n", m);//只有一个工厂
                    break;
                }
                printf("Yes\n");
                sort(v.begin(), v.end(), cmp1);
                for (int k = 0; k < n; k++) {
                    printf("%d", v[k].num);
                    if (k != n - 1)
                        printf(" ");
                }
                printf("\n");
                break;
            }
        }
        //分配失败的时候
        if (flag != true)
            printf("No\n");
    }

    return 0;
}