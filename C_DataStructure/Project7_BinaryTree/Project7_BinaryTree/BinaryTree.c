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

BTnode* CreateCompleteBinaryTree()
{
	BTnode* node1 = BuyNode(1);
	BTnode* node2 = BuyNode(2);
	BTnode* node3 = BuyNode(3);
	BTnode* node4 = BuyNode(4);
	BTnode* node5 = BuyNode(5);
	BTnode* node6 = BuyNode(6);
	BTnode* node7 = BuyNode(7);

	node1->lchild = node2;
	node1->rchild = node3;
	node2->lchild = node4;
	node2->rchild = node5;
	node3->lchild = node6;
	node3->rchild = node7;
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
	printf("\n\n");

	BTnode* croot = CreateCompleteBinaryTree();
	BTnode* sroot1 = BuyNode(0);
	BTnode* sroot2 = BuyNode(0);

	printf("%s\n", BTcomplete1(croot) ? "true" : "false"); //true
	printf("%s\n\n", BTcomplete2(croot) ? "true" : "false"); //true

	printf("%s\n", BTcomplete1(root) ? "true" : "false"); //false
	printf("%s\n\n", BTcomplete2(root) ? "true" : "false"); //false
	croot->lchild->lchild->lchild = BuyNode(11);
	printf("%s\n", BTcomplete1(croot) ? "true" : "false"); //true
	printf("%s\n\n", BTcomplete2(croot) ? "true" : "false"); //true
	croot->lchild->lchild->rchild = BuyNode(12);
	printf("%s\n", BTcomplete1(croot) ? "true" : "false"); //true
	printf("%s\n\n", BTcomplete2(croot) ? "true" : "false"); //true
	croot->lchild->lchild->rchild->rchild = BuyNode(13);
	printf("%s\n", BTcomplete1(croot) ? "true" : "false"); //false
	printf("%s\n\n", BTcomplete2(croot) ? "true" : "false"); //false

	printf("%s\n", BTcomplete1(sroot1) ? "true" : "false"); //true
	printf("%s\n\n", BTcomplete2(sroot1) ? "true" : "false"); //true
	sroot1->rchild = BuyNode(14);
	printf("%s\n", BTcomplete1(sroot1) ? "true" : "false"); //false
	printf("%s\n\n", BTcomplete2(sroot1) ? "true" : "false"); //false
	sroot1->lchild = BuyNode(15);
	printf("%s\n", BTcomplete1(sroot1) ? "true" : "false"); //true
	printf("%s\n\n", BTcomplete2(sroot1) ? "true" : "false"); //true
	sroot2->lchild = BuyNode(16);
	printf("%s\n", BTcomplete1(sroot2) ? "true" : "false"); //true
	printf("%s\n\n", BTcomplete2(sroot2) ? "true" : "false"); //true
	sroot2->lchild->lchild = BuyNode(17);
	printf("%s\n", BTcomplete1(sroot2) ? "true" : "false"); //false
	printf("%s\n\n", BTcomplete2(sroot2) ? "true" : "false"); //false
	sroot2->rchild = BuyNode(18);
	sroot2->rchild->rchild = BuyNode(19);
	printf("%s\n", BTcomplete1(sroot2) ? "true" : "false"); //false
	printf("%s\n\n", BTcomplete2(sroot2) ? "true" : "false"); //false
	sroot2->lchild->lchild->lchild = BuyNode(20);
	sroot2->rchild->rchild->rchild = BuyNode(21);
	printf("%s\n", BTcomplete1(sroot2) ? "true" : "false"); //false
	printf("%s\n\n", BTcomplete2(sroot2) ? "true" : "false"); //false

	BTdestroy(root);
	root = NULL;
	BTdestroy(croot);
	croot = NULL;
	BTdestroy(sroot1);
	sroot1 = NULL;
	BTdestroy(sroot2);
	sroot2 = NULL;
	return 0;
}