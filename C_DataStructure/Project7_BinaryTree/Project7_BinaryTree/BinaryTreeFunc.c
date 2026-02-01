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

BTnode* BTfind(BTnode* root, BTdatatype x) //递归查找某个值
{
	if (!root)
		return NULL;
	if (root->data == x)
		return root;
	BTnode* left = BTfind(root->lchild, x);
	if (left)
		return left;
	BTnode* right = BTfind(root->rchild, x);
	if (right)
		return right;
	return NULL;
}

void LevelOrder(BTnode* root) //层序遍历
{							  //因为队列先进先出，所以从根节点开始，在队头的一定是最靠上层且靠左的节点
	Queue q;				  //取队头节点进行处理，然后处理其子节点，确保子节点在队列中的位置一定按顺序排在本层节点之后
	Queue* pq = &q;
	Qinit(pq);
	if (root)
		Qpush(pq, root);
	while (!Qempty(pq))
	{
		BTnode* front = Qfront(pq); //每次循环取队头节点进行处理
		printf("%d ", front->data);
		Qpop(pq);
		if (front->lchild) //若队头节点有子节点，则入队
			Qpush(pq, front->lchild);
		if (front->rchild)
			Qpush(pq, front->rchild);
	}
	Qdestroy(pq);
}





bool BTcomplete(BTnode* root) //判断是否为完全二叉树，利用层序遍历，若某一层中间出现空则不是完全二叉树
{
	Queue q;
	Queue* pq = &q;
	Qinit(pq);
	bool flag = true;
	if (root)
		Qpush(pq, root);
	while (!Qempty(pq))
	{
		BTnode* front = Qfront(pq);
		if (front && !flag)
		{
			Qdestroy(pq);
			return false;
		}
		if (!front)
			flag = false;
		Qpop(pq);
		if (front)
		{
			Qpush(pq, front->lchild);
			Qpush(pq, front->rchild);
		}
	}
	Qdestroy(pq);
	return true;
}

void BTdestroy(BTnode* root) //销毁二叉树
{
	if (!root)
		return;
	BTdestroy(root->lchild);
	BTdestroy(root->rchild);
	free(root);
}