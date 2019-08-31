#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(int *arr, int start, int end){
    int i = start, j = end;
    int temp = arr[start];
    if (i<j) {
        while(i < j){
            while(i < j && arr[j] >= temp)
                j--;
            if(i < j)
                arr[i++] = arr[j];
            while(i < j && arr[i] <= temp)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = temp;
        quicksort(arr, start, i - 1);
        quicksort(arr, i + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int arr[100] = {0, 5, 6, 8, -5, -9, 1, 4, 3};
    int len = 9;
    quicksort(arr, 0, 8);
    printf("A:");
    int i = 0;
    for(; arr[i] < 0; i++)
        printf("%2d", arr[i]);
    printf("\nB:");
    for(; i < len; i++)
        printf("%2d", arr[i]);

    
    return 0;
}