#include <cmath>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        double t;
        scanf("%lf", &t);
        printf("Case %d: %s\n", i + 1,
               (int)ceil(sqrt(1.0 + t) - 1) & 1 == 1 ? "odd" : "even");
    }
    return 0;
}