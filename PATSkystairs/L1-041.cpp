#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n, cnt = 0;
    while(scanf("%d", &n) == 1){
        cnt++;
        if (n == 250) {
            printf("%d", cnt);
            break;
        }
    }

    return 0;
}
