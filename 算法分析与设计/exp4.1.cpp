#include <cstdio>
#include <iostream>

using namespace std;

#define minn -999999999

//蛮力法 递推子段和 算法复杂度为O(n2)
int maxsum_one(int* arr, int n)
{
    int t, maxsum = minn;
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = i; j < n; j++) {
            t += arr[j];
            if (t > maxsum)
                maxsum = t;
        }
    }
    return maxsum;
}

/**
 * 分治法 二分 分别计算三种情况
 * T(N)=2T(N/2)+O(N)  T(N)=O(NlogN)
 */
int maxsum_two(int* arr, int l, int r)
{
    if (l == r - 1) //l-r中只有一个元素
        return arr[l];
    else if (l == r) //边界l==r时退出递归
        return minn;

    int mid = (l + r) / 2;

    int a = maxsum_two(arr, l, mid); //calculate left part
    int b = maxsum_two(arr, mid + 1, r); //right part

    int maxleft = minn, maxright = minn, temp = 0;
    for (int i = mid; i >= l; i--) //find max subsequence sum from left to center
    {
        temp += arr[i];
        if (temp > maxleft)
            maxleft = temp;
    }
    temp = 0;
    for (int i = mid + 1; i < r; i++) { //find max subsequence sum center  to right
        temp += arr[i];
        if (temp > maxright)
            maxright = temp;
    }
    int c = maxleft + maxright;
    return max(max(a, b), max(b, c)); //union answer
}

/**
 * DP  算法复杂度为O(n)
 */
int maxsum_three(int* arr, int n)
{
    int t = 0, maxsum = minn;
    for (int i = 0; i < n; i++) {
        t = (t + arr[i]) > arr[i] ? (t + arr[i]) : arr[i];
        if (t > maxsum)
            maxsum = t;
    }
    return maxsum;
}

int main(int argc, char const* argv[])
{
    int n = 8;
    int arr[n] = { -1, 3, -2, 6, -6, 1, 6, -1 };
    //int arr[n] = {1,-2,3,4};
    printf("%d\n", maxsum_one(arr, n));
    printf("%d\n", maxsum_two(arr, 0, n));
    printf("%d\n", maxsum_three(arr, n));
    return 0;
}