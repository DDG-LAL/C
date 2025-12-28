#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedListFunc.h"

void LLprint(Node* phead)
{
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
//	phead = tmp; //问题出在这里，此处的phead是链表头指针的拷贝
//				 //把tmp赋值给了一个拷贝，没用
//}

void LLpushfront(Node** pphead, LLdatatype x) //头插
{
	assert(pphead);

	Node* tmp = BuyNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void LLpushback(Node** pphead, LLdatatype x) //尾插
{
	assert(pphead);

	Node* tmp = BuyNode(x);
	//如果是空链表，链表头指针为空，需要改变链表头指针
	//需要改变的是结构体指针的值，因此使用结构体指针的指针，即二级指针
	if (*pphead == NULL) *pphead = tmp;

	//如果是非空链表，不需要改变链表头指针，只需改变末尾节点结构体的next值
	//需要改变的是结构体内容的值，因此使用结构体指针，即一级指针
	//通过二级指针访问一级指针
	else
	{
		Node* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = tmp;
	}
	//需要改变什么变量，就要使用该变量类型的指针
}

void LLpopfront(Node** pphead) //头删
{
	assert(pphead);
	assert(*pphead);

	Node* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);
	tmp = NULL;
}

void LLpopback(Node** pphead) //尾删
{
	assert(pphead);
	assert(*pphead);


	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		Node* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}