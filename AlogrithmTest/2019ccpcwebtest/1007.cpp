#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

char mt[10300][10300];

void copy(int x, int y, int ts, int qua) {
    int edge = 1 << ts;
    if (qua != 2) {
        for (int i = 1; i <= edge; ++i) {
            for (int j = 1; j <= edge; ++j) {
                mt[x + i][y + j] = mt[i][j];
            }
        }
    } else {
        for (int i = 1; i <= edge; ++i) {
            for (int j = 1; j <= edge; ++j) {
                if (mt[i][j] == 'C')
                    mt[x + i][y + j] = 'P';
                else
                    mt[x + i][y + j] = 'C';
            }
        }
    }
}

void cal(int ts) {
    int t = 1 << ts;
    copy(t/2, 0, ts, 2);
    copy(0, t/2, ts, 1);
    copy(t/2, t/2, ts, 3);
}

void print(int ts) {
    int m = 1 << ts;
    for (int j = 1; j <= m; j++) {
        for (int k = 1; k <= m; k++) {
            putchar(mt[j][k]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
    mt[1][1] = 'C';
    mt[1][2] = 'C';
    mt[2][1] = 'P';
    mt[2][2] = 'C';
    for (int i = 2; i <= 10; i++) {
        cal(i);
    }
    int t, op;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &op);
        print(op);
    }
    return 0;
}