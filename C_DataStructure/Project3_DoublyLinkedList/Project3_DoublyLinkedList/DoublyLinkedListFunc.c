#define _CRT_SECURE_NO_WARNINGS 1

#include"DoublyLinkedListFunc.h"

DLLnode* BuyDLLNode(DLLdatatype data) //创建结点
{
	DLLnode* tmp = (DLLnode*)malloc(sizeof(DLLnode));
	if (!tmp)
	{
		perror("malloc\n");
		return NULL;
	}
	tmp->data = data;
	tmp->prev = tmp->next = NULL;
	return tmp;
}

DLLnode* DLLcreate() //初始化
{
	DLLnode* head = BuyDLLNode(-1);
	head->next = head->prev = head;
	return head;
}

bool DLLempty(DLLnode* phead) //判断链表是否为空
{
	assert(phead);
	return phead->next == phead;
}

void DLLprint(DLLnode* phead) //打印
{
	assert(phead);
	DLLnode* cur = phead->next;
	printf("guard <==>");
	while (cur != phead)
	{
		printf(" %d <==>", cur->data);
		cur = cur->next;
	}
	printf(" guard\n\n");
}

void DLLpushback(DLLnode* phead, DLLdatatype x) //尾插
{
	assert(phead);
	//DLLnode* tail = phead->prev;
	//DLLnode* newnode = BuyDLLNode(x);
	//tail->next = newnode;
	//newnode->prev = tail;
	//phead->prev = newnode;
	//newnode->next = phead;

	DLLinsert(phead, x); //复用
}

void DLLpushfront(DLLnode* phead, DLLdatatype x) //头插
{
	assert(phead);
	//DLLnode* front = phead->next;
	//DLLnode* newnode = BuyDLLNode(x);
	//phead->next = newnode;
	//newnode->prev = phead;
	//front->prev = newnode;
	//newnode->next = front;

	DLLinsert(phead->next, x); //复用
}

void DLLpopback(DLLnode* phead) //尾删
{
	assert(phead);
	assert(!DLLempty(phead));
	////if (phead->nextpos == phead)
	//	//return;
	//DLLnode* del = phead->prev, * tail = phead->prev->prev;
	//tail->next = phead;
	//phead->prev = tail;
	//free(del);

	DLLerase(phead->prev); //复用
}

void DLLpopfront(DLLnode* phead) //头删
{
	assert(phead);
	assert(!DLLempty(phead));
	////if (phead->nextpos == phead)
	//	//return;
	//DLLnode* del = phead->next, * front = phead->next->next;
	//front->prev = phead;
	//phead->next = front;
	//free(del);

	DLLerase(phead->next); //复用
}

DLLnode* DLLsearch(DLLnode* phead, DLLdatatype x) //查找
{
	assert(phead);
	assert(!DLLempty(phead));
	DLLnode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void DLLinsert(DLLnode* pos, DLLdatatype x) //指定位置pos前插入
{
	assert(pos);
	DLLnode* pre = pos->prev;
	DLLnode* newnode = BuyDLLNode(x);
	pos->prev = newnode;
	newnode->next = pos;
	newnode->prev = pre;
	pre->next = newnode;
}

void DLLerase(DLLnode* pos) //指定位置删除
{
	assert(pos);
	DLLnode* prepos = pos->prev, * nextpos = pos->next;
	nextpos->prev = prepos;
	prepos->next = nextpos;
	free(pos);
}

void DLLdestroy1(DLLnode* phead) //销毁
{
	assert(phead);
	DLLnode* cur = phead->next;
	while (cur != phead)
	{
		DLLnode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);

	printf("destroyed\n");
}

void DLLdestroy2(DLLnode* phead) //销毁
{
	assert(phead);
	DLLnode* cur = phead->next;

#pragma warning(push)
#pragma warning(disable:6001) //强行忽略C6001警告
	while (cur != phead)
	{
		DLLnode* del = cur;
		cur = cur->next; //C6001警告
		free(del);
	}
	free(phead);
#pragma warning(pop)

	printf("destroyed\n\n");
}