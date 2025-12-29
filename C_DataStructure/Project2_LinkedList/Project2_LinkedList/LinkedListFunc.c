#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkedListFunc.h"

void LLprint(const Node* phead)
{
	const Node* cur = phead;
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
	//需要改变的是结构体成员的值，因此使用结构体指针，即一级指针
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

Node* LLsearch(const Node* phead, LLdatatype x) //查找
{
	while (phead != NULL)
	{
		if (phead->data == x)
			return (Node*)phead;
		else
			phead = phead->next;
	}
	return NULL;
}

void LLinsertBefore(Node** pphead, Node* pos, LLdatatype x) //指定位置pos前插入
{
	assert(pphead);

	if (pos == *pphead)
		LLpushfront(pphead, x); //二级指针用于处理头插
	else if (pos == NULL)
		LLpushback(pphead, x); //二级指针用于处理尾插
	else
	{
		Node* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}

		Node* tmp = BuyNode(x);
		tmp->next = pos;
		pre->next = tmp;
	}
}

void LLinsertAfter(Node* pos, LLdatatype x) //指定位置pos后插入
{
	assert(pos);

	Node* tmp = BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void LLerase(Node** pphead, Node* pos) //指定位置删除
{
	assert(pphead);
	assert(*pphead);

	if (pos == *pphead)
		LLpopfront(pphead); //二级指针用于处理头删
	else if (pos == NULL)
		LLpopback(pphead); //二级指针用于处理尾删
	else
	{
		Node* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		pre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void LLeraseAfter(Node* pos) //指定位置的后一个位置删除
{
	assert(pos);
	assert(pos->next);

	Node* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void LLdestroy(Node* phead) //销毁
{
	while (phead != NULL)
	{
		Node* tmp = phead->next;
		free(phead);
		phead = tmp;
	}

	//需要在函数外部置空链表头指针

	printf("\ndestroyed\n");
}

void LLdestroy2(Node** pphead) //销毁，二级指针版本
{
	assert(pphead);

	Node* cur = *pphead;
	while (cur != NULL)
	{
		Node* tmp = cur->next;
		free(cur);
		cur = tmp;
	}

	*pphead = NULL; //在函数内部置空了链表头指针

	printf("\ndestroyed\n");
}