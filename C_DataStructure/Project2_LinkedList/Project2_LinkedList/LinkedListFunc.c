#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedListFunc.h"

void LLprint(Node* phead)
{
	assert(phead);

	Node* cur = phead;
	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

Node* BuyNode(LLdatatype x)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL)
	{
		perror("malloc");
		return NULL;
	}
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}



//void LLpushfront(Node* phead, LLdatatype x) //错误示范：使用一级指针
//{
//	assert(phead);
//
//	Node* tmp = (Node*)malloc(sizeof(Node));
//	if (tmp == NULL)
//	{
//		perror("malloc");
//		return;
//	}
//	tmp->data = x;
//	tmp->next = phead;
//	phead = tmp; //问题出在这里，此处的phead是链表头指针的拷贝，把tmp赋值给了一个拷贝，没用
//}

void LLpushfront(Node** phead, LLdatatype x) //头插
{
	assert(phead);

	Node* tmp = BuyNode(x);
	tmp->next = *phead;
	*phead = tmp;
}

void LLpushback(Node* phead, LLdatatype x) //尾插
{
	assert(phead);

	Node* tail = phead;
	while ((tail)->next != NULL)
	{
		tail = ((tail)->next);
	}
	Node* tmp = BuyNode(x);
	(tail)->next = tmp;
}