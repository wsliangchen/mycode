#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
//这一题难度基本等同pat乙级25分题目
int ret(int c)
{
    return c == 0 ? 0 : (c == 1 ? 1 : (c == 10 ? 2 : 3));
}

bool cmp(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<int> v[4];
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < 4; i++) //每组数据清空数组
            v[i].clear();
        int choice, inf; //观点和影响力
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &choice, &inf);
            v[ret(choice)].push_back(inf); //分组存不同观点的影响力观点换成二进制
        }
        //除去观点为11的记者从大到小排个序
        for (int i = 0; i < 3; i++)
            sort(v[i].begin(), v[i].end(), cmp);

        double res = 0;//结果可能超过int
        for (int i = 0; i < v[3].size(); i++) //两种观点都支持的记者影响力全部加进去
            res += v[3][i];
        //找到只支持一种观点的记者数量的最小值,然后全加进去
        int minpair = v[1].size() > v[2].size() ? v[2].size() : v[1].size();
        for (int i = 0; i < minpair; i++)
            res += v[1][i] + v[2][i];

        //再将剩下的只支持一种观点的记者存到都不支持的记者中去，为了结果最大化再选和都支持的记者数量一样的记者
        for (int i = minpair; i < v[1].size(); i++)
            v[0].push_back(v[1][i]);
        for (int i = minpair; i < v[2].size(); i++)
            v[0].push_back(v[2][i]);
        sort(v[0].begin(), v[0].end(), cmp); //同样选取影响力最大的
                                             //任选不超过两种观点都支持的人数
        for (int i = 0; i < v[3].size() && i < v[0].size(); i++)
            res += v[0][i];

        printf("%.lf\n", res);
    }
    return 0;
}