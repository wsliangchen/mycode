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
    int w,m,n,ans = 0;
    cin >> w>>m>>n;
    int fm = (m-1)/w, fn = (n-1)/w;
    ans = abs(fm-fn);
    if(ans & 1)
        ans += abs(w-(m-fm*w)+1-(n-fn*w));
    else ans += abs((m-fm*w)-(n-fn*w));
    printf("%d", ans);
    return 0;
}