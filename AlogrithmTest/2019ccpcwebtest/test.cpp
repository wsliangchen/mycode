#include <bits/stdc++.h>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int main(int argc, char const *argv[]){
    ll a = 123321123;
    ll b = 6548565498;
    ll c = 105982242;
    printf("%lld", (a^c)&(b^c));
    return 0;
}