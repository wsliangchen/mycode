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

bool chosen[20];
int order[20],temp[20];
int n,sum;
int flag = 0;
void cal(int k){
    if(k == n+1){
        memcpy(temp,order,sizeof order);
        for(int i = n; i > 1; i--){
            for(int j = 1; j < i; j++)
                temp[j] = temp[j]+temp[j+1];
        }
        if(temp[1] == sum){
            for(int i = 1; i <= n; i++)
                printf("%s%d", i==1?"":" ", order[i]);
            flag = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if(chosen[i]) continue;
        order[k] = i;
        chosen[i] = 1;
        cal(k+1);
        if(flag == 1) break;
        chosen[i] = 0;
        order[k] = 0;
    }
}

int main(int argc, char const *argv[]){
    scanf("%d%d", &n,&sum);
    cal(1);
    return 0;
}