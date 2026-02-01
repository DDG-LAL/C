#define _CRT_SECURE_NO_WARNINGS 1
//【判断子树】
//给出两个二叉树节点root和subRoot
//检验root中是否包含和subRoot具有相同结构和节点值的子树
//存在则返回true，否则返回 false
//二叉树tree的一个子树包括tree的某个节点和这个节点的所有后代节点

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

void BTdestroy(struct TreeNode* root) //销毁二叉树
{
	if (!root)
		return;
	BTdestroy(root->left);
	BTdestroy(root->right);
	free(root);
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

bool isSameTree(struct TreeNode* root1, struct TreeNode* root2)
{
	if (!root1 && !root2)
		return true;
	if (!root1 || !root2)
		return false;
	if (root1->val != root2->val)
		return false;
	return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) //判断是否为子树，遍历root的每个节点
{																//若出现与subRoot相同的树则subRoot是子树
	if (!subRoot)
		return true;
	if (!root)
		return false;
	if (isSameTree(root, subRoot))
		return true;
	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
	struct TreeNode* root = CreateBinaryTree();
	struct TreeNode* sub = CreateBinaryTree();
	printbool(isSubtree(root, sub)); //true
	sub = sub->right;
	printbool(isSubtree(root, sub)); //true
	root->right->right->left = BuyNode(9);
	printbool(isSubtree(root, sub)); //false
	sub->right->left = BuyNode(9);
	printbool(isSubtree(root, sub)); //true
	sub->right->left->val = 1;
	printbool(isSubtree(root, sub)); //false

	BTdestroy(root);
	root = NULL;
	BTdestroy(sub);
	sub = NULL;
	return 0;
}