#include <cstdio>
#include <iostream>

using namespace std;

const int n = 4;

int matrix[n][n];
/**
 * 左右递增上下递增的矩阵可看做一个有序的递增数组
 * 直接二分查找
 * 时间复杂度与二分查找一致   O(log2n)
 */
int find(int n, int f){
    int l = 0, h = n*n-1, mid;
    while(l <= h){
        mid = (l + h) / 2;
        if (f < matrix[mid/n][mid%n])//确定mid在矩阵中的下标
            h = mid - 1;
        else if (f > matrix[mid/n][mid%n])
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    for(int i = 0; i < n; i++)//填充符合要求的矩阵
    {
        for(int j = 0; j < n; j++)
            matrix[i][j] = i * n + j + 1;
    }
    for(int i = 0; i < n; i++)//填充符合要求的矩阵
    {
        for(int j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    int f = 7;
    int ans = find(4, f);
    printf("\nfind %d in matrix %d row %d col\n", f, ans/n+1, ans%n+1);
    return 0;
}