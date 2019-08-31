#include <cstdio>
#include <vector>
using namespace std;

struct Node
{
    int data,next;
};

int main(int argc, char const *argv[])
{
    int firstAdd, n, k, firstIndex;
    scanf("%d%d%d", &firstAdd, &n, &k);

    Node node[100000];//下标当做该节点的地址
    for(int i = 0; i < n; i++)
    {
        int index;
        scanf("%d", &index);
        scanf("%d%d", &node[index].data, &node[index].next);
    }
    //找符合条件的三种元素地址并按顺序记录下来,顺便还可以过滤掉无用元素
    vector<int> res[3];
    int p = firstAdd;
    
    while(p != -1){
        int d = node[p].data;
        d<0?res[0].push_back(p):(d >= 0 && d <= k?res[1].push_back(p):res[2].push_back(p));
        p = node[p].next;
    }
    //仅仅输出并没有做地址交换
    bool isFirstOut = true;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            if(isFirstOut)
            {
                printf("%05d %d ", res[i][j], node[res[i][j]].data);
                isFirstOut = false;
            }else
                printf("%05d\n%05d %d ", res[i][j], res[i][j], node[res[i][j]].data);  
        }
    }
    printf("-1");//末尾地址
    //本篇参考刘婼のblog
    return 0;
}