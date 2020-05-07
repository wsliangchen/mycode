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
    int a,b,c;
    cin >> a>>b>>c;
    int x = c/a+1, y = c/b+1, ans = 0;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++) 
            if(a*i+b*j == c) ans++;
    }
    cout << ans;
    return 0;
}