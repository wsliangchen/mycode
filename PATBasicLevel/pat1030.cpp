#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    double p;//p与最小数相乘可能会超出int范围，所以用double
    scanf("%d%lf", &n, &p);
    double arr[n];
    for (int i = 0; i < n; i++)
        scanf("%lf", &arr[i]);

    sort(arr, arr + n);
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for(int j = i+cnt-1; j < n; j++)//从当前最大长度开始匹配
        {
            if (arr[j] > arr[i]*p) {//如果用等于的话浮点数并不能准确判断相等采取反过来的策略
                break;
            }
            if (cnt < j-i+1) {
                cnt = j - i + 1;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}