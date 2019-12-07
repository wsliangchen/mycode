#include <cstdio>
#include <iostream>
using namespace std;

int n, m, r, c;
int mat[1010][1010], pos = 1;
/*
void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}*/

void deep(int t) {
    //上横行 向右
    for (int i = t, j = t; i <= n - t+1 && j <= m - t; j++) {
        mat[i][j] = pos++;
    }
    //右竖行 向下
    for (int i = t, j = m - t + 1; i <= n - t && j >= m - t; i++) {
        mat[i][j] = pos++;
    }
    //下横行 向左
    for (int i = n - t + 1, j = m - t + 1; i >= t && j > t; j--) {
        mat[i][j] = pos++;
    }
    //左竖行 向上
    for (int i = n - t + 1, j = t; i > t && j <= m - t; i--) {
        mat[i][j] = pos++;
    }
     if (pos >= m * n)
        return;
    deep(t + 1);
}

int main(int argc, char const *argv[]) {
    scanf("%d%d%d%d", &n, &m, &r, &c);
    deep(1);
    //n为偶数 m为奇数没改过来
    if(n&1 && m&1) mat[n/2+1][m/2+1] = pos;
    else if(!(n&1) && m&1) mat[n/2+1][m/2+1] = pos;
    //print();
    printf("%d", mat[r][c]);
    return 0;
}
