#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

#define PI acos(-1.0)
using namespace std;

int main(int argc, char const *argv[]){
    int n,m;
    scanf("%d%d", &n,&m);
    int mat[n][m];
    memset(mat, 0, sizeof mat);
    for(int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        mat[a-1][i] = 1;
        mat[b-1][i] = -1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        { //坑点在于%2d对齐 题目中并未说明
            printf("%s%2d", j == 0?"":" ", mat[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
