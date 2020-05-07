#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;
int arr[1010];
int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+n);
    for(int i = n-1; i >= 0; i--)
        printf("%s%d", i == n-1?"":" ",arr[i]);
    return 0;
}