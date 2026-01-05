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
	DLLnode* tail = phead->prev;
	DLLnode* newnode = BuyDLLNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

void DLLpopback(DLLnode* phead) //尾删
{
	if (phead->next == phead)
		return;
	DLLnode* del = phead->prev, * tail = phead->prev->prev;
	tail->next = phead;
	phead->prev = tail;
	free(del);
}

void DLLpushfront(DLLnode* phead, DLLdatatype x) //头插
{
	assert(phead);
	DLLnode* front = phead->next;
	DLLnode* newnode = BuyDLLNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	front->prev = newnode;
	newnode->next = front;
}

void DLLpopfront(DLLnode* phead) //头删
{
	if (phead->next == phead)
		return;
	DLLnode* del = phead->next, * front = phead->next->next;
	front->prev = phead;
	phead->next = front;
	free(del);
}
