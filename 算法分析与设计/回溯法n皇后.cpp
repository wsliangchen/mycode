#include <cstdio>
#include <cmath>

using namespace std;

#define NUM 20
//n为棋盘大小 x为解向量 sum为可行方案数
int n,x[NUM],sum;

//当前放置位置可行性检验 inline优化函数效率
inline bool Place(int t){
    for(int i = 1; i < t; i++)
        //主副对角线以及所在列检查是否冲突
        if( (abs(t-i) == abs(x[i]-x[t])) || (x[i] == x[t]) )
            return false;
    return true;
}
//t为回溯深度
void Backtrack(int t){
    if(t > n){
        sum++;
        //打印当前可行解
        //for(int i = 1; i <= n; i++) printf("%d", x[i]);
        //printf("\n");
    }else{
        for(int i = 1; i <= n; i++)
        {
            x[t] = i;
            if(Place(t)) Backtrack(t+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    n = 1;
    while(n != 13){
        sum = 0;
        Backtrack(1);
        printf("%d princesses solution numsTotal = %d\n", n, sum);
        n++;
    }
    return 0;
}