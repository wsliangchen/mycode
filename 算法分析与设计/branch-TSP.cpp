#include <iostream>
#include <queue>
using namespace std;

#define inf 1000000
#define NUM 100

int n, m; //n个点  m条边
int a[NUM][NUM]; //图的邻接矩阵
int NoEdge = inf; //图的无边标志
int cc; //当前费用
int bestc; //当前的最小费用
int searchNode; //搜索的节点数

struct node {
    //优先队列以lcost为优先级参考
    friend bool operator<(const node& a, const node& b)
    {
        return a.lcost > b.lcost;
    }
    int lcost; //子树费用下界
    int rcost; //从x[s]~x[n-1]顶点的最小出边
    int cc; //当前费用
    int s; //当前节点的编号
    int x[NUM]; //搜索的路径, 已经找到的路径是x[1]~x[s],继续搜索x[x+1]~x[n]
};

int queueTSP()
{
    priority_queue<node> H;
    int v[NUM];
    int minOut[NUM];
    int minSum = 0;
    int i, j;
    //计算各顶点的最小出边费用
    for (i = 1; i <= n; i++) {
        int Min = NoEdge;
        for (j = 1; j <= n; j++)
            if (a[i][j] < Min)
                Min = a[i][j];
        //无回路
        if (Min == NoEdge)
            return NoEdge;
        minOut[i] = Min;
        minSum += Min;
    }
    //初始化
    node E;
    for (i = 1; i <= n; i++)
        E.x[i] = i;
    E.s = 1;
    E.cc = 0;
    E.rcost = minSum;
    bestc = NoEdge;
    //非叶子节点
    while (E.s < n) {
        //当前拓展节点是叶节点的父节点
        if (E.s == n - 1) {
            //再加上两条边构成的回路，判断所构成的回路是否优于当前最优解
            if (a[E.x[n - 1]][E.x[n]] != NoEdge && a[E.x[n]][1] != NoEdge
                && (E.cc + a[E.x[n - 1]][E.x[n]] + a[E.x[n]][1] < bestc
                       || bestc == NoEdge)) {
                bestc = E.cc + a[E.x[n - 1]][E.x[n]] + a[E.x[n]][1];
                E.cc = bestc;
                E.lcost = bestc;
                E.s++;
                H.push(E);
            } else //不是最优解舍弃拓展节点
                delete[] E.x;
            searchNode++;
        } else { //搜索树的内部结点
            for (i = E.s + 1; i <= n; i++)
                if (a[E.x[E.s]][E.x[i]] != NoEdge) {
                    int cc = E.cc + a[E.x[E.s]][E.x[i]];
                    int rcost = E.rcost - minOut[E.x[E.s]];
                    int B = cc + rcost;
                    if (B < bestc || bestc == NoEdge) {
                        node N;
                        for (j = 1; j <= n; j++)
                            N.x[j] = E.x[j];
                        N.x[E.s + 1] = E.x[i];
                        N.x[i] = E.x[E.s + 1];
                        N.cc = cc;
                        N.s = E.s + 1;
                        N.lcost = B;
                        N.rcost = rcost;
                        H.push(N);
                    }
                }
            delete[] E.x;
        }
        if (H.empty())
            break;
        else {
            E = H.top();
            H.pop();
        }
    }
    if (bestc == NoEdge)
        return NoEdge;
    printf("path = ");
    for (i = 1; i <= n; i++)
        printf("%d-", E.x[i]);
    printf("%d\n", E.x[1]);
    while (!H.empty())
        H.pop();
    printf("min cost = %d\nsearch node = %d\n", bestc, searchNode + 1);
    return bestc;
}

int main()
{
    freopen("branch-TSP.in", "r", stdin);
    scanf("%d%d", &n, &m);
    int i, j;
    //初始化邻接矩阵值为 inf
    fill(a[0], a[0] + n * n, inf);
    int from, to, length;
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &from, &to, &length);
        a[from][to] = a[to][from] = length;
    }
    cc = 0;
    bestc = 0;
    queueTSP();
}
