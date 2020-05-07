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

int cal(int m,int n){
    if(m<n) return 0;
    else if(n == 0) return 1;
    return cal(m-1,n)+cal(m,n-1);
}

int main(int argc, char const *argv[]){
    int n,m;
    scanf("%d%d", &m,&n);
    printf("%d", cal(m,n));
    return 0;
}