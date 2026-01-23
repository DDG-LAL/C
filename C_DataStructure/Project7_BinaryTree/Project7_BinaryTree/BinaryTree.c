#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTreeFunc.h"

BTnode* CreateBinaryTree()
{
	BTnode* node1 = BuyNode(1);
	BTnode* node2 = BuyNode(2);
	BTnode* node3 = BuyNode(3);
	BTnode* node4 = BuyNode(4);
	BTnode* node5 = BuyNode(5);
	BTnode* node6 = BuyNode(6);

	node1->lchild = node2;
	node1->rchild = node4;
	node2->lchild = node3;
	node4->lchild = node5;
	node4->rchild = node6;
	return node1;
}

int main()
{
	BTnode* root = CreateBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);

	printf("\n");
	return 0;
}