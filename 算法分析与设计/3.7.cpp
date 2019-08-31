#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

//数组元素去重
void fun(int *arr, int &len)
{
    map<int, int> mp;
    for (int i = 0; i < len; i++)
        mp[arr[i]]++;
//倒序移动可减少部分移动次数
    for (int i = len - 1; i >= 0; i--)
    {
        if (mp[arr[i]] > 1)
        {
            mp[arr[i]]--;
            for(int j = i; j < len-1; j++)
            {
                arr[j] = arr[j + 1];
            }
            len--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[100] = {3, 5, 4, 8, 4, 5, 6, 5, 4, 9, 4};
    int len = 11;
    fun(arr, len);
    for(int i = 0; i < len; i++)
    {
        printf("%2d", arr[i]);
    }
    
    return 0;
}