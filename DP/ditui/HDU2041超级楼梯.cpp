#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[100], n,a;
    arr[0] = 0, arr[1] = 1;
    for(int i = 2; i < 100; i++)
        arr[i] = arr[i-1] + arr[i-2];
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        printf("%d\n", arr[a]);
    }
    
    return 0;
}