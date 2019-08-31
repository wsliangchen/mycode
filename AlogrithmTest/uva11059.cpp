#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{   
    int n,cnt = 1;
    while(scanf("%d", &n) != EOF){
        long long sum = 0, temp = 1;
        int arr[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        for(int i = 0; i < n; i++)
        {
            temp = 1;
            for(int j = i; j < n; j++)
            {
                temp *= arr[j];
                if(temp > sum) sum =  temp;
            }
        }
        
        printf("Case #%d: The maximum product is %lld.\n", cnt++, sum);
    }
    
    return 0;
}