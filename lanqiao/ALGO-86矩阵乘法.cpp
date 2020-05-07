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
    int m, s, n;
    scanf("%d%d%d", &m, &s, &n);
    int a[m][s], b[s][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < s; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < s; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t=0;
            for(int k = 0; k < s; k++){
                t += a[i][k]*b[k][j];
            }
            printf("%s%d", j==0?"":" ", t);
        }
        printf("\n");
    }

    return 0;
}