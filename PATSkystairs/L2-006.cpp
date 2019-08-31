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

node* in_post(int *post, int *in, int len){
    if (len <= 0) {
        return NULL;
    }
    node *n = new node;
    n->val = post[len - 1];
    int rootIndex = 0;
    for (; rootIndex < len; rootIndex++)
    {
        if (in[rootIndex] == post[len-1])
            break;
    }
    n->l = in_post(post, in, rootIndex);
    n->r = in_post(post + rootIndex, in + rootIndex + 1, len - rootIndex - 1);
    return n;
}

void sequence(node *root){
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        res.push_back(temp->val);
        if(temp->l!=NULL)
            q.push(temp->l);
        if(temp->r!=NULL)
            q.push(temp->r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int post[n], in[n];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];

    node *root = in_post(post, in, n);
    sequence(root);
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s%d", i==0?"":" ",res[i]);
    }
    
    return 0;
}
