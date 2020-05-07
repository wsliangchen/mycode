#include <cstdio>
typedef long long ll;

using namespace std;

int arr[3000000];
int main(int argc, char const *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int st = 0;
        for (int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);
            if (t & 1) st|=(1<<j);
        }
        arr[st]++;
        //printf("i = %d st = %d\n", i, st);
    }
    int test = (1<<m)-1; //得到低m位全1的数
    ll ans = 0;
    for(int i = 0; i < 1<<m; i++){ //枚举所有不同状态
        ans += arr[i]*arr[i^test];
    }
    printf("%lld", ans/2);//去除相反状态多出来的枚举数量
    return 0;
}