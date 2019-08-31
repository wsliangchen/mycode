#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

typedef int status;
typedef char elemtype;

//binary tree struct
typedef struct treeNode
{
    char val;
    struct treeNode *left, *right;
} * node;

//storage node's pointer
queue<node> myqueue;
stack<node> mystack;

void Clean_Queue()
{
    while (myqueue.size() != 0)
        myqueue.pop();
}

void Clean_Stack()
{
    while (mystack.size() != 0)
        mystack.pop();
}

void Initialization_Node(node n)
{
    n->left = NULL;
    n->right = NULL;
    n->val = '\0';
}

void Visit_Node(node n)
{
    printf("%c", n->val);
}

//sequence-order
node Creat_BinaryTree_SequenceOrder()
{                  //creat tree
    int count = 0; //record how many nodes
    char c;
    node root = (treeNode *)malloc(sizeof(treeNode));
    Initialization_Node(root);
    myqueue.push(root); //root node first push to queue

    while (scanf("%c", &c) == 1 && c != '\n')
    {
        treeNode *temp = myqueue.front();
        myqueue.pop();
        temp->val = c; 
        count++;
        temp->left = (treeNode *)malloc(sizeof(treeNode));
        Initialization_Node(temp->left);
        myqueue.push(temp->left);
        temp->right = (treeNode *)malloc(sizeof(treeNode));
        Initialization_Node(temp->right);
        myqueue.push(temp->right);
    }

    Clean_Queue();

    //sequence-order pruning leaves层剪枝
    myqueue.push(root);
    while (!myqueue.empty())
    {
        treeNode *temp = myqueue.front();
        myqueue.pop();
        if (temp->left != NULL)
        {
            if (temp->left->val == '\0')
            {
                free(temp->left);
                temp->left = NULL;
            }
            else
                myqueue.push(temp->left);
        }
        if (temp->right != NULL)
        {
            if (temp->right->val == '\0')
            {
                free(temp->right);
                temp->right = NULL;
            }
            else
                myqueue.push(temp->right);
        }
    }

    return root;
}

//sequence-order traverse
int Traverse_BinaryTree_SequenceOrder(treeNode *root)
{
    int count = 0;
    Clean_Queue();

    myqueue.push(root);
    while (!myqueue.empty())
    {
        treeNode *temp = myqueue.front();
        myqueue.pop();
        Visit_Node(temp);
        count++;
        if (temp->left != NULL)
            myqueue.push(temp->left);
        if (temp->right != NULL)
            myqueue.push(temp->right);
    }
    printf("\nsequence-order traverse node count = %d\n", count);
    return count;
}

//pre-order traverse
int Traverse_BinaryTree_PreOrder(treeNode *root)
{
    int count = 0;
    Clean_Stack();

    mystack.push(root);
    while (!mystack.empty())
    {
        node temp = mystack.top();
        mystack.pop();
        Visit_Node(temp);
        count++;
        if (temp->right != NULL)
            mystack.push(temp->right);
        if (temp->left != NULL)
            mystack.push(temp->left);
    }
    printf("\npre-order traverse node count = %d\n", count);
    return count;
}

//mid-order traverse
int Traverse_BinaryTree_MidOrder(treeNode *root)
{
    int count = 0;
    Clean_Stack();
    node temp = root;
    while (temp != NULL || !mystack.empty())
    {
        while (temp != NULL) //left go first
        {
            mystack.push(temp);
            temp = temp->left;
        }
        temp = mystack.top();
        mystack.pop();
        Visit_Node(temp);
        count++;
        temp = temp->right; //left is empty then visit right node
    }
    printf("\nmid-order traverse node count = %d\n", count);
    return count;
}

//mpost-order traverse
int Traverse_BinaryTree_PostOrder(treeNode *root)
{
    int count = 0;
    Clean_Stack();
    bool flag;
    node temp = root, p = NULL; //p记录父母节点

    if (temp != NULL)
    {
        do{
            while (temp != NULL) //left go first
            {
                mystack.push(temp);
                temp = temp->left;
            }
            p = NULL;
            flag = true;
            while (!mystack.empty() && flag == true)
            {
                temp = mystack.top();
                if (temp->right == p)
                {
                    Visit_Node(temp);
                    count++;
                    mystack.pop();
                    p = temp;
                }
                else
                {
                    temp = temp->right;
                    flag = false;
                }
            }
        }while(!mystack.empty());
    }

    printf("\npost-order traverse node count = %d\n", count);
    return count;
}

//find max depth
int Find_BinaryTree_MaxDepth(treeNode *n)
{
    if(n == NULL)
        return 0;
    int left = Find_BinaryTree_MaxDepth(n->left);
    int right = Find_BinaryTree_MaxDepth(n->right);
    
    return (left>right?left:right)+1;//root node isn't judge
}

int main(int argc, char const *argv[])
{
    node root = Creat_BinaryTree_SequenceOrder();
    Traverse_BinaryTree_SequenceOrder(root);
    Traverse_BinaryTree_PreOrder(root);
    Traverse_BinaryTree_MidOrder(root);
    Traverse_BinaryTree_PostOrder(root);
    int maxdepth = Find_BinaryTree_MaxDepth(root);
    printf("BinaryTree MaxDepth = %d\n", maxdepth);
    return 0;
}
