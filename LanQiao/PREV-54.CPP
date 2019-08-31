
#include <stdio.h>

typedef struct node
{
    int num;            //当前植物的编号
    struct node *Up;    //当前植物上面链接的植物
    struct node *Down;  //当前植物下面链接的植物
    struct node *Left;  //当前植物左面链接的植物
    struct node *Right; //当前植物右面链接的植物
} Node;

void init(Node *, int);
void input(Node *, int, int);
void insert(Node *, int, int, int);
void search(Node *, int, int *, int);
void change(Node *, int *);

int main(void)
{
    int m, n, k, point = 0;
    scanf("%d%d%d", &m, &n, &k);

    Node tree[m * n];  //创建拥有m*n个合根植物的tree结构体数组
    init(tree, m * n); //初始化tree结构体数组
    input(tree, k, n); //输入合根植物连根的情况

    search(tree, m * n, &point, 0); //开始搜索合根植物数

    printf("%d\n", point);
    return 0;
}

void change(Node *root, int *ch)
{
    ch[root->num - 1] = 1; //更新检测数组
    if (root->Up != NULL && ch[root->Up->num - 1] == 0)
    { //分别向四个方向搜索是否有连根情况
        change(root->Up, ch);
    }
    if (root->Down != NULL && ch[root->Down->num - 1] == 0)
    {
        change(root->Down, ch);
    }
    if (root->Left != NULL && ch[root->Left->num - 1] == 0)
    {
        change(root->Left, ch);
    }
    if (root->Right != NULL && ch[root->Right->num - 1] == 0)
    {
        change(root->Right, ch);
    }
}

void search(Node *root, int n, int *pp, int k)
{
    static int check[1000 * 1000] = {0}; //检测数组 记录已经搜索过的连根
    if (k == n)
    { //搜索出口
        return;
    }
    if (check[k] == 0)
    {
        change(&root[k], check); //一个新的合根植物入口，搜索到底
        ++*pp;                   //合根植物数量更新
    }
    search(root, n, pp, k + 1);
}

void insert(Node *root, int head, int tail, int n)
{
    if (head == tail - 1)
    {
        root[head - 1].Right = &root[tail - 1];
        root[tail - 1].Left = &root[head - 1];
    }
    if (head == tail + 1)
    {
        root[head - 1].Left = &root[tail - 1];
        root[tail - 1].Right = &root[head - 1];
    }
    if (head == tail - n)
    {
        root[head - 1].Down = &root[tail - 1];
        root[tail - 1].Up = &root[head - 1];
    }
    if (head == tail + n)
    {
        root[head - 1].Up = &root[tail - 1];
        root[tail - 1].Down = &root[head - 1];
    }
}

void input(Node *root, int k, int n)
{
    int head, tail, i;
    for (i = 0; i < k; i++)
    {
        scanf("%d%d", &head, &tail);
        insert(root, head, tail, n); //更新连根情况
    }
}

void init(Node *root, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        root[i].num = i + 1;
        root[i].Up = NULL;
        root[i].Down = NULL;
        root[i].Left = NULL;
        root[i].Right = NULL;
    }
}
