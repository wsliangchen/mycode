#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	char a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C'};
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	printf("#");
	printf("%c%c", a[r / 13], a[r % 13]);
	printf("%c%c", a[g / 13], a[g % 13]);
	printf("%c%c", a[b / 13], a[b % 13]);
	return 0;
} 