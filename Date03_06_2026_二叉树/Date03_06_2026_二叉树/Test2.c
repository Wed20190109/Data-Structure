#include "Heap.h"
/*
前序遍历
中序遍历
后序遍历
*/

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* newnode(int val)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = val;
	node->left = NULL;
		node->right = NULL;
		return node;
}
TreeNode* createnode()
{
	TreeNode* node1 = newnode(6);
	TreeNode* node2 = newnode(7);
	TreeNode* node3 = newnode(3);
	TreeNode* node4 = newnode(10);
	TreeNode* node5 = newnode(5);
	TreeNode* node6 = newnode(4);
	TreeNode* node7 = newnode(9);
	TreeNode* node8 = newnode(1);
	TreeNode* node9 = newnode(2);
	TreeNode* node10 = newnode(11);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node5->left = node6;
	node3->left = node7;
	node3->right = node8;
	node8->left = node9;
	node8->right = node10;
	return node1;
}

void preorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);

}

void inorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);

	printf("%d ", root->data);
	inorder(root->right);

}

void lastorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
		
		lastorder(root->left);

	lastorder(root->right);
	printf("%d ", root->data);

}

int main()
{
	TreeNode* root = createnode();
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	lastorder(root);
}