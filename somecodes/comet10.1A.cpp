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
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a>> b>> c>>d;
        int x = a*c, y = b*d;
        if(x >= 0 && y >= 0) //同一个象限
            printf("5\n");
        else if((x < 0 && y >= 0) || (x >= 0 && y < 0))//被x=0或y=0其中一个分割
            printf("6\n");
        else
            printf("8\n");
    }
    return 0;
}