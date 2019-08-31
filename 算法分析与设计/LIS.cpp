#include <cstdio>
#include <algorithm>

using namespace std;
int a[100100], b[100100];
int main() {
	int n;
	while(~scanf("%d", &n)) {
		int i, j;
		for(i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		int k = 0;
		b[0] = a[0];
		for(i = 1; i < n; i++) {
			if(a[i] > b[k]) {
				b[++k] = a[i];
			}
			else {
				*lower_bound(b, b + k, a[i]) = a[i];
			}
		}
		printf("%d\n", k + 1);
	}
	return 0;
}