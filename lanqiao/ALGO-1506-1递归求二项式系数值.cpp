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

int cal(int n, int k){
    if(k == 0 || n == k) return 1;
    else return cal(n-1,k)+cal(n-1,k-1);
}

int main(int argc, char const *argv[]){
    int n,k;
    scanf("%d%d", &k,&n);
    printf("%d", cal(n,k));
    return 0;
}