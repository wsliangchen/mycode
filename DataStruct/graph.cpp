#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

//定义边

struct ENode
{
    int v1, v2; //有向边
    int weight;
};
typedef struct ENode *ENodeptr;
typedef ENodeptr Edge;

//图的邻接点定义
typedef struct AdjVNode *AdjVNodeptr;
struct AdjVNode
{
    int adjv;         //下标
    int weight;       //权重
    AdjVNodeptr next; //指向下一个邻接点的指针
};

//表头节点的定义
typedef struct vnode
{
    AdjVNodeptr firstedge; //头指针
    char data;             //顶点数据
} adjlist[100];            //定义邻接表类型和大小

//图节点定义
typedef struct GNode
{
    int nv;    //顶点数
    int ne;    //边数
    adjlist G; //邻接表
};
typedef GNode *GNodeptr;
typedef GNodeptr LGraph; //以邻接表方式存储图

//初始化一个有vnum个顶点但没有边的图
LGraph CreateGraph(int vnum)
{
    int v;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(GNode)); //建立图
    Graph->nv = vnum;
    Graph->ne = 0;

    //初始化邻接表的头指针
    for (v = 0; v < Graph->nv; v++)
    {
        Graph->G[v].firstedge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    AdjVNodeptr NewNode;

    //插入边
    //为v2建立新节点
    NewNode = (AdjVNodeptr)malloc(sizeof(AdjVNode));
    NewNode->adjv = E->v2;
    NewNode->weight = E->weight;

    //将v2插入v1表头
    NewNode->next = Graph->G[E->v1].firstedge;
    Graph->G[E->v1].firstedge = NewNode;

    //无向图还要插入边v2-v1
    NewNode = (AdjVNodeptr)malloc(sizeof(AdjVNode));
    NewNode->adjv = E->v1;
    NewNode->weight = E->weight;

    NewNode->next = Graph->G[E->v2].firstedge;
    Graph->G[E->v2].firstedge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    int v;
    int nv, i;

    scanf("%d", &nv); //读入顶点个数
    Graph = CreateGraph(nv);
    //读入顶点数据
    getchar();
    for (v = 0; v < Graph->nv; v++)
    {
        scanf("%c", &(Graph->G[v].data));
    }

    scanf("%d", &(Graph->ne)); //读入边的个数
    if (Graph->ne != 0)
    {
        E = (Edge)malloc(sizeof(ENode));

        for (i = 0; i < Graph->ne; i++)
        { //边起点终点权重，插入邻接表
            scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}

//深度优先遍历
bool visited[100];
void DFS(LGraph Graph, int i)
{
    visited[i] = true;
    printf("%c", Graph->G[i].data);

    AdjVNodeptr w;
    for (w = Graph->G[i].firstedge; w; w = w->next)
    {
        if (!visited[w->adjv])
        {
            DFS(Graph, w->adjv); //递归访问
        }
    }
}
void DFSTraverse(LGraph Graph)
{
    for (int i = 0; i < 100; i++) //访问记录初始化
    {
        visited[i] = false;
    }
    for (int i = 0; i < Graph->nv; i++)
    {
        if (!visited[i])
        {
            DFS(Graph, i);
        }
    }
}

//广度优先遍历
void BFSTraverse(LGraph Graph)
{
    queue<int> q;
    for (int i = 0; i < 100; i++) //访问记录初始化
    {
        visited[i] = false;
    }
    for (int i = 0; i < Graph->nv; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            printf("%c", Graph->G[i].data);
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(AdjVNodeptr w = Graph->G[u].firstedge; w; w = w->next)
                {
                    if (!visited[w->adjv]) {
                        visited[w->adjv] = true;
                        printf("%c", Graph->G[w->adjv].data);
                        q.push(w->adjv);
                    }
                }
            }
        }
    }
}



int main(int argc, char const *argv[])
{
    LGraph g;
    g = BuildGraph();
    printf("\nDFS:");
    DFSTraverse(g);
    printf("\nBFS:");
    BFSTraverse(g);
    return 0;
}