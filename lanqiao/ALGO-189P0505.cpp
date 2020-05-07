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

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    ll res = n,mod = 1e10;
	while(--n){
		res = res*n%mod;
		while(res%10 == 0) res /= 10;
	}

    printf("%d", res%10);
    return 0;
}