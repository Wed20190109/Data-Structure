#include "Heap.h"
/*
前序遍历:根左右
中序遍历:左根右
后序遍历:左右根
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

void preorder(TreeNode* root)//前序遍历
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);

}

void inorder(TreeNode* root)//中序遍历
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);

	printf("%d ", root->data);
	inorder(root->right);

}

void lastorder(TreeNode* root)//后序遍历
{
	if (root == NULL)
	{
		return;
	}
	
		
	lastorder(root->left);

	lastorder(root->right);
	printf("%d ", root->data);

}

int TreeSize(TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

/* 课后复习
求叶子节点个数
求高度
*/
int TreeLeafSize(TreeNode* root)//求叶子节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


int TreeHight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	int leftNum = TreeHight(root->left);//不用个变量来记录而直接return递归的话会产生巨量的重复计算
	int rightNum = TreeHight(root->right);//

	return leftNum > rightNum ? leftNum + 1 : rightNum + 1;
	//return TTreeHight(root->left)>
}

int TreeKthSize(TreeNode*root)
{
	if (root == NULL)
	{
		return 0;
	}
}


int main()
{
	TreeNode* root = createnode();
	printf("This is preorder\n");
	preorder(root);

	printf("\n");
	printf("This is inorder\n");
	inorder(root);

	printf("\n");
	printf("This is lastorder\n");
	lastorder(root);

	printf("Leaves nodes number:%d", TreeLeafSize(root));
	
	printf("Tree hitght is :%d", TreeHight(root));
}