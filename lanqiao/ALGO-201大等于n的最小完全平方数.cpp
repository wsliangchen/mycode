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
    ll n,f = 0;
    scanf("%lld", &n);
    for(ll i = n;;i++){
        f = sqrt(i);
        if(f*f == i){
            printf("%lld", i);
            break;
        }
    }
    return 0;
}