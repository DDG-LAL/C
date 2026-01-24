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

int size1 = 0;
void BTtreesize1(BTnode* root) //全局变量求节点数
{
	if (!root)
		return;
	size1++;
	BTtreesize1(root->lchild);
	BTtreesize1(root->rchild);
}

int BTtreesize2(BTnode* root) //递归求节点数
{
	return !root ? 0 : BTtreesize2(root->lchild) + BTtreesize2(root->rchild) + 1;
}

int BTleafsize1(BTnode* root) //递归求叶子节点数
{
	if (!root)
		return 0;
	if (!root->lchild && !root->rchild)
		return 1;
	return BTleafsize1(root->lchild) + BTleafsize1(root->rchild);
}

int BTleafsize2(BTnode* root) //递归求叶子节点数，三目写法
{
	return !root ? 0 :
		(!root->lchild && !root->rchild) ? 1 :
		BTleafsize2(root->lchild) + BTleafsize2(root->rchild);
}

int BTtreeheight(BTnode* root) //递归求树高度
{
	if (!root)
		return 0;
	int lheight = BTtreeheight(root->lchild);
	int rheight = BTtreeheight(root->rchild);
	return lheight > rheight ? lheight + 1 : rheight + 1;
}

int BTlevelksize(BTnode* root, int k) //递归求第k层节点数
{
	assert(k > 0);
	if (!root)
		return 0;
	if (k == 1)
		return 1;
	return BTlevelksize(root->lchild, k - 1) + BTlevelksize(root->rchild, k - 1);
}