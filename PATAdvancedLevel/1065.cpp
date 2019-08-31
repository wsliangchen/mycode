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
    
    long long a,b,x,sum;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a,&b,&x);
        sum = a+b;
        if(a>0 && b>0 && sum<0) printf("Case #%d: true\n",i);
        else if(a<0 && b<0 && sum>=0) printf("Case #%d: false\n",i);
        else printf("Case #%d: %s\n",i,sum>x?"true":"false");
    }
    
    return 0;
}