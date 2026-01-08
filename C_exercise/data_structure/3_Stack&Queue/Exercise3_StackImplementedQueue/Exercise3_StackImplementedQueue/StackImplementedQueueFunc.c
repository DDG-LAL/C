#define _CRT_SECURE_NO_WARNINGS 1

#include"StackFunc.h"
#include"StackImplementedQueueFunc.h"

MyQueue* myQueueCreate() //初始化
{
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	if (!obj)
	{
		perror("malloc\n");
		return NULL;
	}
	STinit(&obj->popst);
	STinit(&obj->pushst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) //入队列
{
	STpush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) //出队列
{
	int peek = myQueuePeek(obj);
	STpop(&obj->popst);
	return peek;
}

int myQueuePeek(MyQueue* obj) //获取队头元素
{
	if (STempty(&obj->popst))
	{
		while (!STempty(&obj->pushst))
		{
			STpush(&obj->popst, STtop(&obj->pushst));
			STpop(&obj->pushst);
		}
	}
	int peek = STtop(&obj->popst);
	return peek;
}

bool myQueueEmpty(MyQueue* obj) //判断队列是否为空
{
	return STempty(&obj->popst) && STempty(&obj->pushst);
}

void myQueueFree(MyQueue* obj) //销毁
{
	STdestroy(&obj->popst);
	STdestroy(&obj->pushst);
	free(obj);
}