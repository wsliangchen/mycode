#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int ai[2050] = { 0 }, bi[2050] = { 0 };
        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            ai[t] = 1;
        }
        for (int i = 0; i < m; i++) {
            int t;
            scanf("%d", &t);
            bi[t] = 1;
        }
        bool flag = true;
        int ans = 1e8;
        for(int i = 0; i < 1002; i++)
        {
            flag = true;
            for(int j = 0; j < 1010; j++)
            {
                if(ai[j] == 1 && bi[j+i] == 1){//冲突
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = i;
            }
        }
        for(int i = 0; i < 1001; i++)
        {
            flag = true;
            for(int j = 0; j < 1010; j++)
            {
                if(ai[j+i] == 1 && bi[j] == 1){//冲突
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(i < ans) ans = i;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}