#include <cstdio>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ans = 0,t,data;
        scanf("%d", &t);
        for(int j = 0; j < t; j++)
        {
            scanf("%d", &data);
            if(j > 1 && data > 2) ans^=data-2;
        }
        printf("Case %d: %d\n",i+1,ans);
    }
    
    return 0;
}