#include <bits/stdc++.h>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int arr[100010],arr2[100010];

int main(int argc, char const *argv[]){
    int t,n,temp;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr2[i]);
        sort(arr,arr+n);
        sort(arr2,arr2+n);
        for(int i = 0; i < n-1; i++)
            printf("%d ", arr[i]^arr2[i]);
        printf("%d\n", arr[n]^arr2[n]);
    }
    
    return 0;
}