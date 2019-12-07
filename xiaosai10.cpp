#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, d;
struct T {
    double x, y, h;
};
T t[10100];
double maxsum = 0.0;

bool cmp(T a, T b) {
    return a.h > b.h;
}

void dfs(int j, double sum) {
    if (sum > maxsum)
        maxsum = sum;
    for (int i = j + 1; i < n; i++) {
        if (t[i].h < t[j].h) {
            //判断条件与题目描述相反
            double dis = sqrt(pow(t[i].x - t[j].x, 2) + pow(t[i].y - t[j].y, 2) + pow(t[i].h - t[j].h, 2));
            if (dis <= d) {
                dis = sqrt(pow(t[j].x - t[i].x, 2) + pow(t[j].y - t[i].y, 2));
                dfs(i,sum+dis);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        t[i].x = a, t[i].y = b, t[i].h = c;
    }
    scanf("%d", &d);
    sort(t, t + n,cmp);
    dfs(0, 0.0);
    printf("%.2lf", maxsum);
    return 0;
}
