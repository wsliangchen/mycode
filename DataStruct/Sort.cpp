#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h> //获得系统时间
#include <time.h>
#define MAX 100000
int arr[MAX];
long t_start, t_end;
using namespace std;

void grouping(int *arr, int start, int end, int *temp);
void merge(int *arr, int start, int end, int mid, int *temp);
void HeapAdjust(int *arr, int index, int length);

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序    时间复杂度O(n^2)
void BubbleSort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) //相邻两个交换
            if (arr[j] < arr[i])
                Swap(&arr[j], &arr[i]);
    }
}

//选择排序    时间复杂度O(n^2)
//比冒泡排序只是减少交换次数增加了对比次数
void SelectSort(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        int min = i;
        for (int j = i + 1; j < length;j++) //找到没有对比的元素中最小的和当前位置元素交换
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            Swap(&arr[i], &arr[min]);
    }
}

//插入排序    时间复杂度O(n^2)
//将无序元素插入到有序序列
//在数列基本有序的情况下效率高，在元素较少的时候效率高,否则移动元素次数很多效率低
void InsertSort(int *arr,
                int length) { //把第一个元素当做有序序列，从第二个元素开始遍历
    for (int i = 1; i < length; i++) {
        if (arr[i] < arr[i - 1]) {
            int temp = arr[i]; //先记录下当前对比数据，否则后面移动会覆盖丢失
            int j; //只要比下标为i-1的元素小于就往后移，第i-1个位置始终留给插入的数据
            for (j = i - 1; j >= 0 && temp < arr[j]; j--)
                arr[j + 1] = arr[j];
            arr[j + 1] = temp; //插入
        }
    }
}

//希尔排序  又名减少增量排序
//插入排序改进  先分组  再对每一组分别进行插入排序  减少移动元素次数
//分组增量  实验得出 increment/3 + 1 平均效率最高
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

//快速排序
//分治法 + 挖坑填数
//实验得出在元素大于20个以后平均效率最好
/*
快速排序有三大缺点
1.糟糕的最坏时间复杂性（O(n^2)）
2.不稳定性
3.不具有适应性（或说具有反适应性，被处理数组越接近排序状态时排序越慢）。
受到偏爱的原因就是它在实际使用中“比较快”，快就是好。*/
//递归实现
void RecursiveQuickSort(int *arr, int start, int end) {
    int i = start, j = end;
    int temp = arr[start]; //基准数
    if (i < j)             //前后指针重合时退出递归
    { //每次指针移动都必须判断前后指针是否重合
        while (i < j) { //每轮直到前后指针重合退出
            //从右向左 找比基准数小的数
            while (i < j && arr[j] >= temp) {
                j--;
            }
            //找到填坑
            if (i < j) {
                arr[i] = arr[j];
                i++; //
            }
            //从左向右 找比基准数大的数
            while (i < j && arr[i] < temp) {
                i++;
            }
            //找到填坑
            if (i < j) {
                arr[j] = arr[i];
                j--;
            }
        }
        //一轮结束 把基准数放到i或j
        arr[i] = temp;
        RecursiveQuickSort(arr, start, i - 1); //剩下左半部分递归排序
        RecursiveQuickSort(arr, i + 1, end);   //剩下右半部分递归排序
    }
}

//归并排序 时间复杂度O(nlgn) 空间复杂度O(n)
//改进版本原地归并排序 可以将辅助空间复杂度从O(n)降至O(1)
void RecursiveMergeSort(int *arr, int start, int end) {
    int *temp = (int *)malloc(sizeof(int) * (end - start)); //申请辅助空间
    end--; // end当做最后一个元素下标来用要减一
    grouping(arr, start, end, temp); //递归分组合并

    free(temp);
}
//递归分组
void grouping(int *arr, int start, int end, int *temp) { //一直分组
    if (start >= end)
        return;
    int mid = (start + end) / 2;       //找到中间分组
    grouping(arr, start, mid, temp);   //左半边
    grouping(arr, mid + 1, end, temp); //右半边
    merge(arr, start, end, mid, temp);
}
//合并算法
void merge(int *arr, int start, int end, int mid,
           int *temp) { //找到两组合并界限
    int i_start = start, i_end = mid, j_start = mid + 1, j_end = end;
    int length = 0; //表示辅助空间有多少元素
    //循环合并
    while (i_start <= i_end && j_start <= j_end) {
        if (arr[i_start] < arr[j_start]) //两组对比并且按顺序放到辅助空间中
        {
            temp[length] = arr[i_start];
            i_start++;
            length++;
        } else {
            temp[length] = arr[j_start];
            j_start++;
            length++;
        }
    } //第一轮合并处理完i或j序列会有剩余的一个数
    //处理i序列剩下的数
    while (i_start <= i_end) {
        temp[length] = arr[i_start];
        i_start++;
        length++;
    }
    //处理j序列剩余的数
    while (j_start <= j_end) {
        temp[length] = arr[j_start];
        j_start++;
        length++;
    }
    //辅助空间数据覆盖原空间
    for (int i = 0; i < length; i++) {
        arr[start + i] = temp[i];
    }
}

//堆排序
void RecursiveHeapSort(
    int *arr,
    int length) { // i当做下标  需要/2 -1
                  // 一维数组按照层序想象成完全二叉树，最后一个非叶子节点就是lenght/2的位置
    //初始化堆：先从上到下构造成大顶堆
    for (int i = length / 2 - 1; i >= 0; i--) {
        //测试用        printf("i = %d\n", i);
        HeapAdjust(arr, i, length);
    }
    //交换堆顶元素和最后一个元素
    for (int i = length - 1; i >= 0; i--) {
        Swap(&arr[0], &arr[i]);
        //每次交换完第一个和无序的最后一个元素后无序序列递减
        HeapAdjust(arr, 0, i);
    }
}

// arr待调整的数组  index待调整的节点下标  length待调整的数组长度
void HeapAdjust(int *arr, int index, int length) {
    //先保存父节点的下标
    int max = index;
    //保存左右孩子的下标
    int lchild =
        index * 2 + 1; // index是下标所以找的是二叉树中index的孩子节点下标
    int rchild = index * 2 + 2;
    //找到三个节点中最大的那个下标并且放到父亲节点的位置
    //保证数组不能越界
    if (lchild < length && arr[lchild] > arr[max]) {
        max = lchild;
    }
    if (rchild < length && arr[rchild] > arr[max]) {
        max = rchild;
    }
    if (max != index) { //如果原来根节点的元素不是最大的那个  进行交换
        Swap(&arr[max], &arr[index]);
        //交换后的max节点可能不符合大顶堆概念递归继续调整
        HeapAdjust(arr, max, length);
    }
}

//打印函数
void PrintArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

//获取系统时间
long getSystemTime() {
    struct timeb tb;
    ftime(&tb); //精确到毫秒
    // printf("%ld\n", tb.time);
    return tb.time * 1000 + tb.millitm;
}
//产生随机数
void Random(int *arr) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX; i++)
        arr[i] = rand() % MAX;
}
void Start() { t_start = getSystemTime(); }
void End() { t_end = getSystemTime(); }
long RunTime() { return t_end - t_start; }

struct cmpfunctor {
    inline bool operator()(const int &a, const int &b) { return a < b; }
};

int main(int argc, char const *argv[]) {
    printf("Sort %d random items.\n", MAX);
    /*
//冒泡排序
    Random(arr);
//   PrintArray(arr, MAX);
    Start();
    BubbleSort(arr, MAX);
    End();
//   PrintArray(arr, MAX);
    printf("BubbleSort used time : %ldms\n", RunTime());

//选择排序
    Random(arr);
//    PrintArray(arr, MAX);
    Start();
    SelectSort(arr, MAX);
    End();
//    PrintArray(arr, MAX);
    printf("SelectSort used time : %ldms\n", RunTime());

//插入排序
    Random(arr);
//    PrintArray(arr, MAX);
    Start();
    InsertSort(arr, MAX);
    End();
//    PrintArray(arr, MAX);
    printf("InsertSort used time : %ldms\n", RunTime());

//希尔排序
    Random(arr);
//    PrintArray(arr, MAX);
    Start();
    ShellSort(arr, MAX);
    End();
//    PrintArray(arr, MAX);
    printf("ShellSort used time : %ldms\n", RunTime());
*/
    //递归快速排序
    Random(arr);
    //    PrintArray(arr, MAX);
    Start();
    RecursiveQuickSort(arr, 0, MAX - 1);
    End();
    //    PrintArray(arr, MAX);
    printf("RecursiveQuickSort used time : %ldms\n", RunTime());
    Random(arr);
    //    PrintArray(arr, MAX);
    Start();
    sort(arr, arr + MAX - 1);
    End();
    //    PrintArray(arr, MAX);
    printf("STLSort used time : %ldms\n", RunTime());
    Random(arr);
    //    PrintArray(arr, MAX);//functor作为sort参数进行排序
    Start();
    sort(arr, arr + MAX - 1, cmpfunctor());
    End();
    //    PrintArray(arr, MAX);
    printf("STL functor sort used time : %ldms\n", RunTime());
    /*
    //递归归并排序
        Random(arr);
    //    PrintArray(arr, MAX);
        Start();
        RecursiveMergeSort(arr,0, MAX);
        End();
    //    PrintArray(arr, MAX);
        printf("RecursiveMergeSort used time : %ldms\n", RunTime());

    //递归堆排序
        Random(arr);
      //  PrintArray(arr, MAX);
        Start();
        RecursiveHeapSort(arr, MAX);
        End();
      //  PrintArray(arr, MAX);
        printf("RecursiveHeapSort used time : %ldms\n", RunTime());*/
    return 0;
}