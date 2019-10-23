#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int t;
    cin >> t;

    while(t--){
        int a,b,c,d,k,x = 0, y = 0;
        cin >> a >> b >> c >> d >> k;
        y = b/d;
        if(b % d) y++;
        x = k-y;
        if(x*c < a) printf("-1\n");
        else printf("%d %d\n", x,y);
    }
    return 0;
}