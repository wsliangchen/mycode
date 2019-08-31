#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10050;

int matrix[maxn][maxn];

int main(int argc, char const *argv[])
{
    int n, m,np;
    scanf("%d%d", &n, &m);
    memset(matrix, 0, sizeof(matrix));
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &np);
        int arr[np];
        for(int j = 0; j < np; j++){
            int temp;
        }
            scanf("%d", &temp);
        
    }
    
    return 0;
}