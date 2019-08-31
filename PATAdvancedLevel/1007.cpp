#include <cstdio>
#include <iostream>

using namespace std;

bool flag = true;//记录是否有出现过大于零的子段和

int max1(int& l,int& h, int* arr, int n){
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(int j = i; j < n; j++)
        {
            temp += arr[j];
            if(temp > ans){
                flag = false;
                l = arr[i], h = arr[j];
                ans = temp;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int low = arr[0],high = arr[n-1],ans = 0;
    ans = max1(low,high,arr,n);
    printf("%d %d %d", ans, flag?0:low,flag?0:high);
    return 0;
}