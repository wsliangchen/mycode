#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
typedef long long ll;

#define PI acos(-1.0)
using namespace std;

map<int,int> mp;

int main(int argc, char const *argv[]){
    int n,temp = 0,ans = 0;
    scanf("%d", &n);
    if(n <= 0) return 0;
    while(n--){
        int t;
        scanf("%d", &t);
        mp[t]++;
        if(mp[t] > mp[temp]){
            temp = t;
            ans = mp[t];
        }else if(mp[t] == mp[temp]){
            temp = min(t,temp);
        }
    }
    printf("%d", temp);
    return 0;
}