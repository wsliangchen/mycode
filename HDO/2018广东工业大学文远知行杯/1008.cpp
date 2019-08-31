#include <cstdio>
using namespace std;

#define N 5000001
//500ms
int main(int argc, char const *argv[])
{//每四次操作就会回到原来位置不用管路径
    int arr[N];//暴力打表直接跑

    for(int i = 2; i < N; i++)
    {
        int temp = 2;
        for(int j = i*2; j < N; j += i)
        {
            arr[j] += temp;
            temp++;
        }
    }

    int n;
    while(scanf("%d", &n) == 1){
        double sum = 0;
        for(int i = 2; i <= n; i++)
            sum += arr[i];
        printf("%.lf\n", sum*4+n-1);
    }
    return 0;
}