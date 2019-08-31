#include <cstdio>
#include <cstring>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int res = 1 << n;
    printf("2^%d = %d", n, res);
    return 0;
}
