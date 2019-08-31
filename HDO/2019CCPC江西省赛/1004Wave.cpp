#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int arr[100050];
int main(int argc, char const *argv[])
{
    
    int n,c,temp = 0,ans = 0;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for(int i = 1; i <= c; i++)
    {
        for(int j = i+1; j <= c; j++)
        {
            temp = 0;
            for(int k = 0; k < n; k++)
            {
                if(temp&1){//判断偶数位
                    if(arr[k] == j) temp++;
                }else{
                    if(arr[k] == i) temp++;
                }
            }
            if(temp > ans) ans = temp;
        }
    }
    for(int i = 1; i <= c; i++)
    {
        for(int j = i+1; j <= c; j++)
        {
            temp = 0;
            for(int k = 0; k < n; k++)
            {
                if(temp&1){//判断偶数位
                    if(arr[k] == i) temp++;
                }else{
                    if(arr[k] == j) temp++;
                }
            }
            if(temp > ans) ans = temp;
        }
    }
    printf("%d", ans);

    return 0;
}