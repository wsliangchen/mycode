#include <cstdio>
#include <algorithm>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int low = 0, high = 0;
    for(int i = 0; i < n/2; i++)
        low += a[i];
    for(int i = n/2; i < n; i++)
        high += a[i];

    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", (n+1)/2, n/2, high-low);
    
    return 0;
}
