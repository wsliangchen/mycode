#include <cstdio>

using namespace std;
int main(int argc, char const *argv[])
{
    int n,t;
    scanf("%d%d", &n , &t);
    int arr[n+1];
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    
    t = t % n;//求模
    bool printed = false;//记录第一个是否被打印
    for(int i = n-t+1; i <= n; i++)
    {
        printf("%s%d", (i == n-t+1)?"":" ", arr[i]);
        printed = true;
    }
                                    //第一次打印后改变printed
    for(int i = 1; i < n-t+1; i++, printed = true)
        printf("%s%d", (printed == false)?"":" ", arr[i]);
    
    return 0;
}