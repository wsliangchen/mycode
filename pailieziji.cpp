#include <cstdio>
#include <iostream>

using namespace std;

void print_premutation(int n, int* a, int cur)
{
    if (cur == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            int ok = 1;
            for (int j = 0; j < cur; j++) {
                if (a[j] == i)
                    ok = 0;
            }
            if (ok) {
                a[cur] = i;
                print_premutation(n, a, cur + 1);
            }
        }
    }
}

void print_subset(int n, int s)
{
    for (int i = 0; i < n; i++) {
        if (s & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(int argc, char const* argv[])
{
    int A[10000];
    print_premutation(5, A, 0);
    int n = 3;
    for(int i = 0; i < (1<<n); i++)
    {
        print_subset(n,i);
    }
    
    
    return 0;
}