#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

vector<int> res;

struct node
{
    int val;
    struct node *l, *r;
};

queue<node *> q;

node* pre_in(int *pre, int *in, int len){
    if (len <= 0)
        return NULL;

    node *n = new node;
    n->val = *pre;
    int rootIndex = 0;
    for( rootIndex = 0; rootIndex < len; rootIndex++)
    {
        if (*pre == in[rootIndex])
            break;
    }
    n->l = pre_in(pre + 1, in, rootIndex);
    n->r = pre_in(pre + rootIndex + 1, in + rootIndex + 1, len - (rootIndex + 1));
    return n;
}

void sequence(node *root){
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        res.push_back(temp->val);
        if(temp->r!=NULL)
            q.push(temp->r);
        if(temp->l!=NULL)
            q.push(temp->l);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int pre[n], in[n];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> pre[i];

    node *root = pre_in(pre, in, n);
    sequence(root);
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s%d", i==0?"":" ",res[i]);
    }
    
    return 0;
}
