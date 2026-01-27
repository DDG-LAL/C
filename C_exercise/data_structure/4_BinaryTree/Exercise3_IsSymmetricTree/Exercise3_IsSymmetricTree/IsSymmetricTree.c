#define _CRT_SECURE_NO_WARNINGS 1
//【对称二叉树】
//给出一个二叉树，判断是否为轴对称二叉树

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

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
	struct TreeNode* node2 = BuyNode(3);
	struct TreeNode* node3 = BuyNode(3);
	struct TreeNode* node4 = BuyNode(0);
	struct TreeNode* node5 = BuyNode(6);
	struct TreeNode* node6 = BuyNode(6);
	struct TreeNode* node7 = BuyNode(0);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	return node1;
}

void printbool(bool b)
{
	printf("%s\n\n", b ? "true" : "false");
}

bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) //判断对称二叉树(子函数)
{
	if (!left && !right) //若两节点均为空，返回true
		return true;
	if (!left || !right) //若只有其中一个节点存在，返回false
		return false;
	if (left->val != right->val) //若两节点均存在，且val值不同，返回false
		return false;
	return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left); //若两节点均存在且val值相同，则检查下一层
}

bool isSymmetric(struct TreeNode* root) //判断对称二叉树
{
	if (!root)
		return true;
	return _isSymmetric(root->left, root->right);
}

int main()
{
	struct TreeNode* root = CreateBinaryTree();
	printbool(isSymmetric(root)); //true
	root->left->left->val = 100;
	printbool(isSymmetric(root)); //false
	root->right->right->val = 100;
	printbool(isSymmetric(root)); //true
	root->left->right->left = BuyNode(11);
	printbool(isSymmetric(root)); //false
	root->right->left->right = BuyNode(11);
	printbool(isSymmetric(root)); //true
	root->right->left->right->val = 36;
	printbool(isSymmetric(root)); //false

	return 0;
}