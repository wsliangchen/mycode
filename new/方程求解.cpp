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
double mid = 0.0;

void cal(double l, double r) {
    if (r - l < 1e-11) 
        return;
    mid = l + (r-l) / 2;
    double s = mid * mid * mid - 5 * mid * mid + 10 * mid - 80;
    if (s < 0)
        l = mid;
    else
        r = mid;
    cal(l, r);
}

int main(int argc, char const *argv[]) {
    cal(0.0, 10.0);
    printf("%.9lf", mid);
    return 0;
}