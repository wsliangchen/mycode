#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int n = 0;
    while (a >= 2 && b >= 1 && d >= 2) {
        n++;
        a -= 2, b -= 1, d -= 2;
    }
    printf("%d\n", n);
    n = 0;
    while (a >= 1 && b >= 1 && c >= 1 && d >= 1) {
        n++;
        a -= 1, b -= 1, c -= 1, d -= 1;
    }
    printf("%d\n", n);
    n = 0;
    while (c >= 2 && d >= 1) {
        n++;
        c -= 2, d -= 1;
    }
    printf("%d\n", n);
    n = 0;
    while(b >= 3){
        n++;
        b-=3;
    }
    printf("%d\n", n);
    n = 0;
    while (a >= 1 && d >= 1) {
        n++;
        a -= 1, d -= 1;
    }
    printf("%d\n", n);
    n = 0;
    return 0;
}