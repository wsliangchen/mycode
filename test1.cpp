#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", (n + 1) / 2 + 1);
    }
    return 0;
}