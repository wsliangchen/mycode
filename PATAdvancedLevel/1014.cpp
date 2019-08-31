#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, q;
int custm[1010];
struct w {
    int no;      //窗口编号
    int mintime; //该窗口最小排队时间
    int endtime; //该窗口上一个人的结束时间
    int peonum;  //当前人数
    queue<int> q;
};

int main(int argc, char const *argv[]) {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    struct w wd[n];
    for (int i = 0; i < n; i++)
        wd.no = i;
    for (int i = 1; i <= k; i++)
        scanf("%d", &custm[i]);
    int i;
    for(i = 0; i < k && i < n*m; i++)
    {
        wd[i].q.push(i+1);
    }
    
    return 0;
}