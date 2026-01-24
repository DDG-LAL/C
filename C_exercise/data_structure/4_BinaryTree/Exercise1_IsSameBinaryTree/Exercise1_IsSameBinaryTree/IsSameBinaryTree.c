#define _CRT_SECURE_NO_WARNINGS 1
//【相同二叉树】
//给出两个二叉树的根节点，检验两树是否相同
//若两树在结构上相同，且节点具有相同的值，则认为是相同的

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* BuyNode(int x) //创建节点
{
	struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (!newnode)
	{
		perror("malloc\n");
		return NULL;
	}
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

struct TreeNode* CreateBinaryTree()
{
	struct TreeNode* node1 = BuyNode(1);
	struct TreeNode* node2 = BuyNode(2);
	struct TreeNode* node3 = BuyNode(3);
	struct TreeNode* node4 = BuyNode(4);
	struct TreeNode* node5 = BuyNode(5);
	struct TreeNode* node6 = BuyNode(6);
	struct TreeNode* node7 = BuyNode(7);
	struct TreeNode* node8 = BuyNode(8);
	struct TreeNode* node9 = BuyNode(9);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->left = node7;
	node5->right = node8;
	node7->left = node9;
	return node1;
}

int main()
{
	struct TreeNode* root1 = CreateBinaryTree();
	struct TreeNode* root2 = CreateBinaryTree();
	printf("%s\n\n", isSameTree(root1, root2) ? "true" : "false");
	root2->left->left = NULL;
	printf("%s\n\n", isSameTree(root1, root2) ? "true" : "false");

	return 0;
}