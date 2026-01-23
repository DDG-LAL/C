#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTreeFunc.h"

BTnode* BuyNode(BTdatatype x) //创建节点
{
	BTnode* newnode = (BTnode*)malloc(sizeof(BTnode));
	if (!newnode)
	{
		perror("malloc\n");
		return NULL;
	}
	newnode->data = x;
	newnode->lchild = newnode->rchild = NULL;
	return newnode;
}

void PreOrder(BTnode* root) //前序遍历
{
	if (!root)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(BTnode* root) //中序遍历
{
	if (!root)
	{
		printf("N ");
		return;
	}
	InOrder(root->lchild);
	printf("%d ", root->data);
	InOrder(root->rchild);
}

void PostOrder(BTnode* root) //后序遍历
{
	if (!root)
	{
		printf("N ");
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%d ", root->data);
}