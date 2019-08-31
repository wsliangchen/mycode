#include <cstdio>

using namespace std;
int main() {

    int a, b;
    scanf("%d%d", &a, &b);
    int sum = 0, max = b-a+1;
    int i;
    for(i = 1; i <= max; i++)
    {
        sum += a;
        printf("%5d%s", a, i%5==0?"\n":"");
        a++;
    }
    printf("%sSum = %d", (i-1)%5==0?"":"\n", sum);

    return 0;
}
