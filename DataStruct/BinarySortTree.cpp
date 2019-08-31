#include <cstdio>
#include <iostream>

using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
};

bool search_bst(TreeNode *node, int key)
{
    if (node == NULL)
        return false;
    else
    {
        if (key == node->key)
        {
            return true;
        }
        else if (key < node->key)
            return search_bst(node->left, key); //进左子树搜索
        else
            return search_bst(node->right, key); //进右子树搜索
    }
}

void insert(TreeNode *&t, int key)
{
    if (t == NULL) {
        t = (TreeNode *)malloc(sizeof(TreeNode));
        t->key = key;
        t->left = t->right = NULL;
    }
    if (key < t->key) {
        insert(t->left, key);
    }else if (key > t->key) {
        insert(t->right, key);
    }
}

void mk_bst(TreeNode * &root, int key)
{
    if (search_bst(root, key) == NULL)
    { //查找失败插入
        insert(root, key);
    }
}

void midorder(TreeNode *t)
{
    if (t == NULL)
        return;

    midorder(t->left);
    printf("%d  ", t->key);
    midorder(t->right);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = NULL;
    int arr[8] = {5, 9, 2, 0, 3, 4, 1};
    for (int i = 0; i < 8; i++)
    {
        mk_bst(root, arr[i]);
    }

    midorder(root);
    printf("输入要查找的key:");
    int key;
    scanf("%d", &key);

    if (search_bst(root, key)) {
        printf("找到%d", key);
    }else
    {
        printf("未找到%d", key);
    }
    
    return 0;
}