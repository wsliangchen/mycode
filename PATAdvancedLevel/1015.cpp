#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 1e5+10;

int prime(int x){
    if(x == 1) return 0;
    for(int i = 2; i*i<= x; i++)
        if(x % i == 0) return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    int n = 0,d,num[maxn];

    while(scanf("%d", &n) && n > 0){
        if(n < 0) break;
        scanf("%d", &d);

        if(prime(n) == 0) {printf("No\n"); continue;}
        else{
            int cnt = 0, sum = 0,k = 0;
            do{
                num[cnt++] = n%d;//进行d进制下的翻转
                n /= d;
            }while(n);

            for(int i = cnt-1; i >= 0; i--)
            {
                sum += num[i]*pow(d,k);
                k++;
            }
            if(prime(sum))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}