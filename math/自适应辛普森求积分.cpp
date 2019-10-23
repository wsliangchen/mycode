#include <cmath>
#include <cstdio>
using namespace std;
// hud1724 求解椭圆面积
const double eps = 1e-5; //辛普森计算精度,一般比要求精度多两位即可
double a, b, l, r;
double f(double x) { // x关于y的函数
    double y = b * sqrt(1.0 - (x * x) / (a * a));
    return y;
}

double simpson(double a, double b) { //辛普森积分公式
    return (f(a) + f(b) + 4.0 * f((a + b) / 2.0)) * (b - a) / 6.0;
}
double ars(double a, double b, double eps) {
    double c = (a + b) / 2.0;
    double mid = simpson(a, b), l = simpson(a, c), r = simpson(c, b);
    if (fabs(l + r - mid) <= 15 * eps)
        return l + r + (l + r - mid) / 15.0;
    return ars(a, c, eps / 2.0) + ars(c, b, eps / 2.0);
}
int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf%lf", &a, &b, &l, &r);
        printf("%.3lf\n", 2.0 * ars(l, r, eps)); //递归求辛普森
    }
    return 0;
}