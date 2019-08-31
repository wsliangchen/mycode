//算法1

#include <iostream>
#include <fstream>
#include <string>

struct TreeNode
{
	struct TreeNode *left;
	struct TreeNode *right;
	char elem;
};

TreeNode *BinaryTreeFromOrderings(char *inorder, char *preorder, int length)
{
	if (length == 0)
	{
		return NULL;
	}
	TreeNode *node = new TreeNode;
	node->elem = *preorder;
	int rootIndex = 0;
	for (; rootIndex < length; rootIndex++)
	{
		if (inorder[rootIndex] == *preorder)
			break;
	}
	node->left = BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex);
	node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
	std::cout << node->elem << std::endl;
	free(node);
	return NULL;
}

int main(int argc, char **argv)
{
	char *pr = "GDAFEMHZ";
	char *in = "ADEFGHMZ";
	BinaryTreeFromOrderings(in, pr, 8);
	printf("\n");
	return 0;
}