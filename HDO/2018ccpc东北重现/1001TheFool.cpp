#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {

    for (int i = 1; i <= 30; i++) {
        // scanf("%d", &t);
        int odd = 0;
        for (int j = 1; j <= i; j++)
            odd = odd ^ (i / j);
        printf("Case %d: %s\n", i, odd & 1 == 1 ? "odd" : "even");
    }

    return 0;
}