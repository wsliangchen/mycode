#include <iostream>
#include <cstdio>

using namespace std;

void SiftHeap(int r[], int k, int n)
{
    int i, j;

    i = k;
    j = 2 * i + 1; //置i为要筛的结点，j为i的左孩子
    while (j < n)  //筛选还没有进行到叶子
    {
        if (j < n - 1 && r[j] < r[j + 1])
            j++;         //比较i的左右孩子，j为较大者
        if (r[i] > r[j]) //根结点已经大于左右孩子中的较大者
            break;
        else
        {
            swap(r[i], r[j]); //将被筛结点与结点j交换
            i = j;
            j = 2 * i + 1; //被筛结点位于原来结点j的位置
        }
    }
}