#define _CRT_SECURE_NO_WARNINGS 1

#include"SinglyLinkedListFunc.h"

void SLLprint(const SLLnode* phead)
{
	const SLLnode* cur = phead;
	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLLnode* BuyNode(SLLdatatype x)
{
	SLLnode* tmp = (SLLnode*)malloc(sizeof(SLLnode));
	if (tmp == NULL)
	{
		perror("malloc");
		return NULL;
	}
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

//void SLLpushfront(SLLnode* phead, SLLdatatype x) //错误示范：使用一级指针
//{
//	assert(phead);
//
//	SLLnode* tmp = (SLLnode*)malloc(sizeof(SLLnode));
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

void SLLpushfront(SLLnode** pphead, SLLdatatype x) //头插
{
	assert(pphead);

	SLLnode* tmp = BuyNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void SLLpushback(SLLnode** pphead, SLLdatatype x) //尾插
{
	assert(pphead);

	SLLnode* tmp = BuyNode(x);
	//如果是空链表，链表头指针为空，需要改变链表头指针
	//需要改变的是结构体指针的值，因此使用结构体指针的指针，即二级指针
	if (*pphead == NULL) *pphead = tmp;

	//如果是非空链表，不需要改变链表头指针，只需改变末尾节点结构体的next值
	//需要改变的是结构体成员的值，因此使用结构体指针，即一级指针
	//通过二级指针访问一级指针
	else
	{
		SLLnode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = tmp;
	}
	//需要改变什么变量，就要使用该变量类型的指针
}

void SLLpopfront(SLLnode** pphead) //头删
{
	assert(pphead);
	assert(*pphead);

	SLLnode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);
	tmp = NULL;
}

void SLLpopback(SLLnode** pphead) //尾删
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
		SLLnode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

SLLnode* SLLsearch(const SLLnode* phead, SLLdatatype x) //查找
{
	while (phead != NULL)
	{
		if (phead->data == x)
			return (SLLnode*)phead;
		else
			phead = phead->next;
	}
	return NULL;
}

void SLLinsertBefore(SLLnode** pphead, SLLnode* pos, SLLdatatype x) //指定位置pos前插入
{
	assert(pphead);

	if (pos == *pphead)
		SLLpushfront(pphead, x); //二级指针用于处理头插
	else if (pos == NULL)
		SLLpushback(pphead, x); //二级指针用于处理尾插
	else
	{
		SLLnode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}

		SLLnode* tmp = BuyNode(x);
		tmp->next = pos;
		pre->next = tmp;
	}
}

void SLLinsertAfter(SLLnode* pos, SLLdatatype x) //指定位置pos后插入
{
	assert(pos);

	SLLnode* tmp = BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void SLLerase(SLLnode** pphead, SLLnode* pos) //指定位置删除
{
	assert(pphead);
	assert(*pphead);

	if (pos == *pphead)
		SLLpopfront(pphead); //二级指针用于处理头删
	else if (pos == NULL)
		SLLpopback(pphead); //二级指针用于处理尾删
	else
	{
		SLLnode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}
		pre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLLeraseAfter(SLLnode* pos) //指定位置的后一个位置删除
{
	assert(pos);
	assert(pos->next);

	SLLnode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void SLLdestroy(SLLnode* phead) //销毁
{
	while (phead != NULL)
	{
		SLLnode* tmp = phead->next;
		free(phead);
		phead = tmp;
	}

	//需要在函数外部置空链表头指针

	printf("\ndestroyed\n");
}

void SLLdestroy2(SLLnode** pphead) //销毁，二级指针版本
{
	assert(pphead);

	SLLnode* cur = *pphead;
	while (cur != NULL)
	{
		SLLnode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}

	*pphead = NULL; //在函数内部置空了链表头指针

	printf("\ndestroyed\n");
}