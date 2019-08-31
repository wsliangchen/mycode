#include <cstdio>
#include <iostream>

using namespace std;

//在线处理算法
//在任何时候停止输入都可以得到当前的正确的解
//线性复杂度
int MaxSubseqSum(int *arr, int n)
{
    int thissum, maxsum;
    thissum = maxsum = 0;
    for(int i = 0; i < n; i++)
    {
        thissum += arr[i];
        if (thissum > maxsum) {//当前子列合大于最大子列合的时候更新最大子列合
            maxsum = thissum;
        }else if (thissum < 0) {//当前子列合为负直接扔掉，因为后面的数加上一个负数肯定会变小
            thissum = 0;
        }
    }
}


/**下面是分治求解子列合的算法 */

int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer( int List[], int left, int right )
{ /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }

    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

int main(int argc, char const *argv[])
{
    int arr[] = {-1, -3, -2, 6, -6, 1, 6, -1};
    int max = MaxSubseqSum(arr, 8);
    printf("%d\n", max);  
    printf("%d", MaxSubseqSum3(arr, 8));
    return 0;
}