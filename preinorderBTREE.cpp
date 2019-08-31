#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    char val;
    struct node *l, *r;
};

node *pre_inbtree(char *preorder, char *inorder, int length)
{
    if (length == 0)
    {
        return NULL;
    }
    node *n = new node;
    n->val = *preorder;
    int rootIndex = 0;
    for (; rootIndex < length; rootIndex++)
    {
        if (inorder[rootIndex] == *preorder)
        {
            break;
        }
    }
    n->l = pre_inbtree(preorder + 1, inorder, rootIndex);
    n->r = pre_inbtree(preorder + rootIndex + 1, inorder + rootIndex + 1, length - (rootIndex + 1));
    cout << n->val;
    return n;
}

node *in_post(char *post, char *in, int len)
{
    if (len <= 0)
    {
        return NULL;
    }
    node *n = new node;
    n->val = post[len - 1];
    int rootIndex = 0;
    for (; rootIndex < len; rootIndex++)
    {
        if (in[rootIndex] == post[len - 1])
        {
            break;
        }
    } /*
    printf("%d", rootIndex);
    return NULL;*/
    n->l = in_post(post, in, rootIndex);
    n->r = in_post(post + rootIndex, in + rootIndex+1, len - (rootIndex + 1));
    cout << n->val;
    return n;
}

struct node *create(char a[], char b[], int n)
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    if (n <= 0)
        return NULL;
    else
    {
        root->val = b[n - 1];
        char *p;
        for (p = a; p != '\0'; p++)
        {
            if (*p == b[n - 1])
                break;
        }
       
        int t = p - a;
         printf("%d", t);
        root->l = create(a, b, t);
        root->r = create(a + t + 1, b + t, n - t - 1);
        cout << root->val;
        return root;
    }
}

void pretravers(node *root)
{
    cout << root->val;
    if (root->l != NULL)
    {
        pretravers(root->l);
    }
    if (root->r != NULL)
    {
        pretravers(root->r);
    }
}

int main(int argc, char const *argv[])
{
    char *pr = "GDAFEMHZ";
    char *in = "ADEFGHMZ";
    char *post = "AEFDHZMG";
    /*
    node* n = pre_inbtree(pr, in, strlen(pr));
    pretravers(n);*/
    node* nn = in_post(post, in, strlen(post));
    pretravers(nn);/*
    node *nnn = create(in, post, strlen(post));
    pretravers(nnn);*/
    return 0;
}