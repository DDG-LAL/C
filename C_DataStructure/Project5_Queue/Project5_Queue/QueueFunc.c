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
		pq->phead = pq->ptail = newnode;
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	pq->size++;
}

void Qpop(Queue* pq) //出队列
{
	assert(pq);
	assert(!Qempty(pq));
	Qnode* newhead = pq->phead->next;
	free(pq->phead);
	pq->phead = newhead;
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
