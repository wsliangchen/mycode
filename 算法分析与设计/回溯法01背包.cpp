#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define NUM 100
//c背包容量n物品数量cw当前重量 cv当前价值 bestv最优
int c,n,cw,cv,bestv;

struct Object
{
    int w;    //重量
    int v;    //价值
    double d; //单位价值重量比
}Q[NUM]; //物品数组
//排序因子 按照单位价值从大到小
bool cmp(Object a, Object b){
    return a.d >= b.d;
}
//界限函数剪枝
int Bound(int i){
    int cleft = c - cw; //背包剩余容量
    int b = cv;         //上界
    while(i < n && Q[i].w <= cleft){//尽可能多的装入背包
        cleft -= Q[i].w;
        b += Q[i].v;
        i++;
    }
    if(i < n) b += 1.0*cleft*Q[i].v/Q[i].w;
    return b;
}

void backtrack(int i)
{
	if (i+1>n) {bestv = cv; return;}//到达叶子节点更新最优值
    //验证比bestv大以后继续进入下层, 否则剪枝
	if (cw+Q[i].w<=c)//左子树 选取第i个物品
	{
		cw += Q[i].w;
		cv += Q[i].v;
		backtrack(i+1);
		cw -= Q[i].w;
		cv -= Q[i].v;
	}
	if (Bound(i+1)>bestv) backtrack(i+1);//右子树 不选第i个
}

int main()
{
    freopen("Knapsack.in", "r", stdin);
	while(scanf("%d",&c) && c)
	{
		cw = 0;
		cv = 0;
		bestv = 0;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&Q[i].w,&Q[i].v);
			Q[i].d = 1.0*Q[i].v/Q[i].w;
		}
		sort(Q, Q+n, cmp);
		backtrack(0);
		printf("%d\n", bestv);
	}
	return 0;
}