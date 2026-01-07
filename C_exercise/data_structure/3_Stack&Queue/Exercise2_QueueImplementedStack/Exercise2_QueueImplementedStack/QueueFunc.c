#define _CRT_SECURE_NO_WARNINGS 1

#include"QueueFunc.h"

void Qinit(Queue* pq) //初始化
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

bool Qempty(Queue* pq) //判断队列是否为空
{
	assert(pq);
	return 0 == pq->size;
}

void Qpush(Queue* pq, Qdatatype x) //入队列
{
	assert(pq);
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	if (!newnode)
	{
		perror("malloc\n");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (Qempty(pq))
	{
		assert(!pq->phead);
		assert(!pq->ptail);
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

void Qpop(Queue* pq) //出队列
{
	assert(pq);
	assert(!Qempty(pq));

	//Qnode* newhead = pq->phead->next;  //不分类处理，容易出错
	//free(pq->phead);
	//pq->phead = newhead;
	//pq->size--;
	//if (Qempty(pq))
	//	pq->ptail = NULL;

	if (!pq->phead->next)//分类处理，不易出错，一个结点和多个结点的情况分别处理
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL; //一个结点需要把ptail置空
	}
	else
	{
		Qnode* newhead = pq->phead->next; //多个结点直接头删
		free(pq->phead);
		pq->phead = newhead;
	}
	pq->size--;
}

Qdatatype Qfront(Queue* pq) //获取队头元素
{
	assert(pq);
	assert(!Qempty(pq));
	return pq->phead->data;
}

Qdatatype Qback(Queue* pq) //获取队尾元素
{
	assert(pq);
	assert(!Qempty(pq));
	return pq->ptail->data;
}

int Qsize(Queue* pq) //获取队列内元素个数
{
	assert(pq);
	return pq->size;
}

void Qdestroy(Queue* pq) //销毁
{
	assert(pq);
	Qnode* cur = pq->phead;
	while (cur)
	{
		Qnode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;

	printf("destroyed\n\n");
}
