#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while(scanf("%d", &n) == 1){
        double d;
        string s;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>s;
            int t = s[s.find('.')+3]-'0';
            if(t >= 5) ans += 1.0*(10-t);
            else ans -= 1.0*t;
        }
        printf("%.3lf\n", 1.0*ans/1000);
    }

    return 0;
}