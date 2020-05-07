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

int arr[110][110];
int t[110];
int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            scanf("%d", &arr[i][j]);
    }
    for(int i = n-1; i >= 0;i--){
        for(int j = 0; j < i+1; j++)
            t[j] = arr[i][j]+max(t[j], t[j+1]);
    }
    printf("%d", t[0]);
    return 0;
}