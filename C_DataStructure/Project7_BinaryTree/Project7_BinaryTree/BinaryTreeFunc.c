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
		Qpop(pq);
		printf("%d ", front->data);
		if (front->lchild) //若队头节点有子节点，则入队
			Qpush(pq, front->lchild);
		if (front->rchild)
			Qpush(pq, front->rchild);
	}
	Qdestroy(pq);
}

bool BTcomplete1(BTnode* root) //判断是否为完全二叉树，利用层序遍历
{							   //若遍历过程中出现空节点，则标记
	Queue q;				   //标记后，若在遍历结束前出现非空节点，则false
	Queue* pq = &q;			   //若直到遍历结束都没有出现非空节点，则true
	Qinit(pq);
	bool flag = true;
	if (root)
		Qpush(pq, root);
	while (!Qempty(pq))
	{
		BTnode* front = Qfront(pq);
		Qpop(pq);
		if (front && !flag) //之前出现过空节点，且当前节点非空
		{
			Qdestroy(pq);
			return false;
		}
		if (!front) //第一次出现空节点，标记
			flag = false;
		if (front) //当前节点的子节点入队
		{
			Qpush(pq, front->lchild);
			Qpush(pq, front->rchild);
		}
	}
	Qdestroy(pq);
	return true;
}

bool BTcomplete2(BTnode* root) //判断是否为完全二叉树，利用层序遍历
{							   //若遍历过程中出现空节点，则停止遍历，观察后续节点
	Queue q;				   //若后续均为空节点，则true，若后续出现非空节点，则false
	Queue* pq = &q;
	Qinit(pq);
	if (root)
		Qpush(pq, root);
	while (!Qempty(pq))
	{
		BTnode* front = Qfront(pq);
		Qpop(pq);
		if (!front) //第一次遇到空节点，跳出，此时若是完全二叉树，后续节点均为空
			break;
		Qpush(pq, front->lchild);
		Qpush(pq, front->rchild);
	}
	while (!Qempty(pq))
	{
		BTnode* front = Qfront(pq);
		Qpop(pq);
		if (front) //后续节点中出现非空
		{
			Qdestroy(pq);
			return false;
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