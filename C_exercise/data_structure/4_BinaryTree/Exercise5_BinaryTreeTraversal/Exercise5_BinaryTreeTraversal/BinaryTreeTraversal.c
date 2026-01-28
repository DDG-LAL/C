#define _CRT_SECURE_NO_WARNINGS 1
//【遍历二叉树并返回】
//给出二叉树根节点，以数组形式返回前序遍历/中序遍历/后序遍历

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

int treeSize(struct TreeNode* root)
{
	return !root ? 0 : treeSize(root->left) + treeSize(root->right) + 1;
}

void _preorderTraversal(struct TreeNode* root, int* arr, int* pi) //前序遍历子函数
{													   //int* pi这个参数是用于从函数内部修改函数外部的变量值，属于输出型参数
	if (!root)										   //作为下标的i不能直接参与递归，因为每次递归调用的i都在不同栈帧
		return;
	arr[(*pi)++] = root->val; //写入arr
	_preorderTraversal(root->left, arr, pi);
	_preorderTraversal(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) //前序遍历
{											//int* returnSize这个参数是用于从函数内部修改函数外部的变量值，属于输出型参数
	*returnSize = treeSize(root); //统计root大小
	int* arr = (int*)malloc(sizeof(int) * (*returnSize)); //依据大小申请空间
	int i = 0;
	_preorderTraversal(root, arr, &i); //写入arr
	return arr;
}

void _inorderTraversal(struct TreeNode* root, int* arr, int* pi) //中序遍历子函数
{													  //int* pi这个参数是用于从函数内部修改函数外部的变量值，属于输出型参数
	if (!root)										  //作为下标的i不能直接参与递归，因为每次递归调用的i都在不同栈帧
		return;
	_inorderTraversal(root->left, arr, pi);
	arr[(*pi)++] = root->val; //写入arr
	_inorderTraversal(root->right, arr, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) //中序遍历
{										   //int* returnSize这个参数是用于从函数内部修改函数外部的变量值，属于输出型参数
	*returnSize = treeSize(root); //统计root大小
	int* arr = (int*)malloc(sizeof(int) * (*returnSize)); //依据大小申请空间
	int i = 0;
	_inorderTraversal(root, arr, &i); //写入arr
	return arr;
}

void _postorderTraversal(struct TreeNode* root, int* arr, int* pi) //后序遍历子函数
{														//int* pi这个参数是用于从函数内部修改函数外部的变量值，属于输出型参数
	if (!root)											//作为下标的i不能直接参与递归，因为每次递归调用的i都在不同栈帧
		return;
	_postorderTraversal(root->left, arr, pi);
	_postorderTraversal(root->right, arr, pi);
	arr[(*pi)++] = root->val; //写入arr
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) //后序遍历
{											 //int* returnSize这个参数是用于从函数内部修改函数外部的变量值，属于输出型参数
	*returnSize = treeSize(root); //统计root大小
	int* arr = (int*)malloc(sizeof(int) * (*returnSize)); //依据大小申请空间
	int i = 0;
	_postorderTraversal(root, arr, &i); //写入arr
	return arr;
}

int main()
{
	struct TreeNode* root = CreateBinaryTree();
	int size = 0;
	int* arr1 = preorderTraversal(root, &size); //前序遍历
	for (int i = 0; i < size; ++i)
		printf("%d ", arr1[i]);
	printf("\n\n");

	int* arr2 = inorderTraversal(root, &size); //中序遍历
	for (int i = 0; i < size; ++i)
		printf("%d ", arr2[i]);
	printf("\n\n");

	int* arr3 = postorderTraversal(root, &size); //后序遍历
	for (int i = 0; i < size; ++i)
		printf("%d ", arr3[i]);
	printf("\n\n");

	return 0;
}