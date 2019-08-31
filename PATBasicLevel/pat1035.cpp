#include <cstdio>
#include <iostream>

using namespace std;

int arr[105];

bool compare(int *a, int length)
{
    for(int i = 0; i < length; i++)
        if (arr[i] != a[i])
            return false;
    return true;
}

bool insertSort(int *a, int length)
{
    for(int i = 1; i < length; i++)
    {
        if (a[i] < a[i-1]) {
            int temp = a[i];//记录下当前对比的数据
            int j;          //依次往后移直到找到合适的位置
            for(j = i-1; j >= 0 && temp < a[j]; j--)
                a[j + 1] = a[j];
            a[j] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[n], b[n];//拷贝出来两个副本用于推演迭代
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        a[i] = b[i] = arr[i];
    }

    insertSort(a, n);


    return 0;
}