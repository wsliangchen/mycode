#include <cstdio>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

void qsort(int *arr, int s, int e) {
    int i = s, j = e, temp = arr[s];
    if (i >= j)
        return;
    while (i < j) {
        while (i < j && arr[j] >= temp)
            --j;
        if (i < j)
            arr[i++] = arr[j];
        while (i < j && arr[i] < temp)
            ++i;
        if (i < j)
            arr[j--] = arr[i];
    }
    arr[i] = temp;
    qsort(arr, s, i);
    qsort(arr, i + 1, e);
}

void shellsort(int *arr, int length) {
    int increment = length;
    while (increment > 1) {
        increment = increment / 3 + 1;
        for (int i = 0; i < increment; i++) {
            for (int j = i + increment; j < length; j += increment) {
                if (arr[j] < arr[j - increment]) {
                    int temp = arr[j];
                    int k;
                    for (k = j - increment; k >= 0 && temp < arr[k];
                         k -= increment) {
                        arr[k + increment] = arr[k];
                    }
                    arr[k + increment] = temp;
                }
            }
        }
    }
}
void ShellSort(int *arr, int length) {
    int increment = length;
    int i, j, k;
    do { //确定分组增量   分组增量逐渐递减  元素趋于有序
         //再进行插入排序减少移动次数
        increment = increment / 3 + 1;
        for (i = 0; i < increment; i++) //插入排序的增量为1
        {
            for (j = i + increment; j < length; j += increment) {
                if (arr[j] < arr[j - increment]) {
                    int temp = arr[j];
                    for (k = j - increment; k >= 0 && temp < arr[k]; k -= increment) {
                        arr[k + increment] = arr[k];
                    }
                    arr[k + increment] = temp;
                }
            }
        }
    } while (increment > 1);
}
int main(int argc, char const *argv[]) {
    int arr[] = {3, 1, 2, 5, 7, 9, 5, 2};
    qsort(arr, 0, 7);
    //shellsort(arr, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}