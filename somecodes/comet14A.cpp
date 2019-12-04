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
    double n,a,b,r,x,y;
    int ans = 0;
    cin >> n >> a >> b>>r;
    while(n--){
        cin >> x >> y;
        double t = (x-a)*(x-a)+(y-b)*(y-b);
        if(t <= r*r) ans ++;
    }
    cout << ans;
    return 0;
}