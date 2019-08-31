#include <cstdio>
#include <iostream>

#define NUM 500
#define MAXINT 210000000

using namespace std;

int matrix[NUM][NUM];//定义邻接矩阵

//n为顶点个数
void Prim(int n, int matrix[][NUM])
{
    int lowcost[NUM];
    int closest[NUM];
    bool s[NUM] = {false};//记录顶点是否被访问过

    for(int i = 1; i <= n; i++)//初始化记录表
    {
        lowcost[i] = matrix[1][i];
        closest[i] = 1;
        s[i] = false;
    }

    s[1] = true;//从第一个顶点开始处理
    for(int i = 1; i < n; i++)
    {   //在未处理的节点中找到最小边权的节点
        int min = MAXINT;
        int j = 1;
        for(int k = 2; k <= n; k++)
        {
            if (lowcost[k] < min && s[k] == false) {
                min = lowcost[k];
                j = k;
            }
        }

        printf("loop %d find edge :%d to %d\n", i, closest[j], j);
        s[j] = true;
        for(int k = 2; k <= n; k++)//将可能是下次循环要找的边收入
        {
            if (matrix[j][k] < lowcost[k] && s[k] == false) {
                lowcost[k] = matrix[j][k];//将每个顶点相接的权值最小边收入集合
                closest[k] = j;//将该点收入集合
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;//n个顶点m条边

    FILE *fp = fopen("prim.in", "r");
    //读取邻接矩阵
    while(fscanf(fp,"%d%d", &n,&m) != EOF && n != 0){
        int i, j;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= n; j++)//初始化每个顶点都不连通
                matrix[i][j] = MAXINT;
        }

        int v1, v2, w;//边的起点终点权值
        for(int i = 0; i < m; i++)
        {
            fscanf(fp,"%d%d%d", &v1, &v2, &w);
            matrix[v1][v2] = w;
            matrix[v2][v1] = w;
        }
        Prim(n, matrix);
        printf("\n");
    }
    getchar();
    return 0;
}