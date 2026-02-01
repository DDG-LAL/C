#define _CRT_SECURE_NO_WARNINGS 1
//【单值二叉树】
//给出一个二叉树，判断是否为单值二叉树
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树

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
	struct TreeNode* node1 = BuyNode(9);
	struct TreeNode* node2 = BuyNode(9);
	struct TreeNode* node3 = BuyNode(9);
	struct TreeNode* node4 = BuyNode(9);
	struct TreeNode* node5 = BuyNode(9);
	struct TreeNode* node6 = BuyNode(9);
	struct TreeNode* node7 = BuyNode(9);
	struct TreeNode* node8 = BuyNode(9);
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

void printbool(bool b)
{
	printf("%s\n\n", b ? "true" : "false");
}

bool isUnivalTree2(struct TreeNode* root) //满足条件的角度，很繁琐
{
	if (!root) //空节点，返回true
		return true;
	if (!root->left && !root->right) //叶子节点，返回true
		return true;
	if (!root->left && root->right) //只有右子节点
	{
		if (root->val == root->right->val) //右子节点等于父节点
			return isUnivalTree2(root->right); //检查右子节点
		else
			return false; //右子节点不等于父节点
	}
	if (!root->right && root->left) //只有左子节点
	{
		if (root->val == root->left->val) //左子节点等于父节点
			return isUnivalTree2(root->left); //检查左子节点
		else
			return false; //左子节点不等于父节点
	}
	if (root->val == root->left->val && root->val == root->right->val) //左右子节点均存在且等于父节点
		return isUnivalTree2(root->left) && isUnivalTree2(root->right); //检查左右子节点
	return false; //左右子节点均存在且其中至少一个不等于父节点
}

//对于某个子节点，只存在以下情况: 1.不存在 -> 返回true
//								  2.存在 
//									2.1.等于父节点 -> 继续判断子节点的子节点
//									2.2.不等于父节点 -> 返回false

bool isUnivalTree(struct TreeNode* root) //违反条件的角度，简洁高效
{
	if (!root) //空节点，返回true
		return true;
	if (root->left && root->val != root->left->val) //若左子节点存在且不等于父节点，返回false
		return false;
	if (root->right && root->val != root->right->val) //若右子节点存在且不等于父节点，返回false
		return false;
	return isUnivalTree(root->left) && isUnivalTree(root->right); //其余情况，检查子节点
}
//多数情况下，从违反条件的角度构建会更清晰明了
// 
//适用违反条件判断的要素: 1.违规情况简单明确(非法路径少)
//						  2.需要尽早终止(一旦违规就无需后续检查)
//						  3.成功情况复杂多样(合法路径多)
//
//适用满足条件判断的要素: 1.成功路径清晰有限(合法情况少到能被枚举)
//						  2.需要收集所有信息(需要完整遍历)
//						  3.边界情况处理为主(专门处理特例)

int main()
{
	struct TreeNode* root = CreateBinaryTree();
	printbool(isUnivalTree(root)); //true
	printbool(isUnivalTree2(root)); //true
	root->right->left->left->left->val = 1;
	printbool(isUnivalTree(root)); //false
	printbool(isUnivalTree2(root)); //false

	BTdestroy(root);
	root = NULL;
	return 0;
}