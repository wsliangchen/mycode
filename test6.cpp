#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define PI acos(-1)

int main(int argc, char const *argv[]) {
    double x1, x2, x3, y1, y2, y3, p, a, b, c, s, d;
    while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3)) {
        a = sqrt(pow(fabs(y1 - y2), 2) + pow(fabs(x1 - x2), 2));
        b = sqrt(pow(fabs(y2 - y3), 2) + pow(fabs(x2 - x3), 2));
        c = sqrt(pow(fabs(y1 - y3), 2) + pow(fabs(x1 - x3), 2));
        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        d = a * b * c / (2 * s);
        printf("%.2lf\n", d * PI);
    }
    return 0;
}