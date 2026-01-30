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
	BTnode* node7 = BuyNode(7);
	BTnode* node8 = BuyNode(8);
	BTnode* node9 = BuyNode(9);

	node1->lchild = node2;
	node1->rchild = node4;
	node2->lchild = node3;
	node4->lchild = node5;
	node4->rchild = node6;
	node5->lchild = node7;
	node5->rchild = node8;
	node7->lchild = node9;
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
	printf("\n\n");

	size1 = 0;
	BTtreesize1(root);
	printf("%d ", size1);
	size1 = 0;
	BTtreesize1(root);
	printf("%d\n", size1);
	size1 = 0;
	printf("\n");

	printf("%d ", BTtreesize2(root));
	printf("%d\n\n", BTtreesize2(root));

	printf("%d ", BTleafsize1(root));
	printf("%d ", BTleafsize1(root));
	printf("%d ", BTleafsize2(root));
	printf("%d\n\n", BTleafsize2(root));

	int h = BTtreeheight(root);
	printf("%d\n\n", h);

	for (int i = 1; i <= h; ++i)
		printf("%d ", BTlevelksize(root, i));
	printf("\n\n");

	BTnode* tmp = BTfind(root, 9);
	tmp->data = 111;
	PreOrder(root);
	printf("\n\n");

	LevelOrder(root);

	printf("\n");
	return 0;
}