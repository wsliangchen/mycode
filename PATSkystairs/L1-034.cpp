#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int arr[1010] = {0};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        for(int j = 0; j < t; j++)
        {
            int temp;
            scanf("%d", &temp);
            arr[temp]++;
        }
    }

    int max = -1,index = 0;

    for(int i = 1009; i >= 0; i--)
    {
        if (arr[i] > max) {
            index = i;
            max = arr[i];
        }
    }
    
    printf("%d %d", index, arr[index]);
    return 0;
}
