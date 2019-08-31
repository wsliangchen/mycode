#include <cstdio>
#include <iostream>

using namespace std;

void RecursiveQuickSort(int *arr, int start, int end)
{
    int i = start, j = end;
    int temp = arr[start];//基准数
    if(i < j)//前后指针重合时退出递归
    {       //每次指针移动都必须判断前后指针是否重合
        while(i<j){//每轮直到前后指针重合退出
            while(i<j && arr[j] >= temp) j--;
            if (i < j) arr[i++] = arr[j];
            while(i<j && arr[i] < temp) i++;
            if (i<j) arr[j--] = arr[i];
        }
        arr[i] = temp;
        RecursiveQuickSort(arr, start, i-1);
        RecursiveQuickSort(arr, i+1, end);
    }
}


int main(int argc, char const *argv[])
{
    int n = 8;
    int a[n] = {1,3,5,9,6,0,-11,-8};
    RecursiveQuickSort(a, 0, 8);
    printf("set A include : ");
    for(int i = 0; i < n/2; i++)
        printf("%4d", a[i]);
    printf("\nset B include : ");
    for(int i = n/2; i < n; i++)
        printf("%4d", a[i]);
    
    return 0;
}