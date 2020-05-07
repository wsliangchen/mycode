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

int gcd(int a, int b){
    return b == 0?a:gcd(b,a%b);
}

int main(int argc, char const *argv[]){
    int a,b;
    scanf("%d%d", &a,&b);
    printf("%d", a/gcd(a,b)*b);
    return 0;
}