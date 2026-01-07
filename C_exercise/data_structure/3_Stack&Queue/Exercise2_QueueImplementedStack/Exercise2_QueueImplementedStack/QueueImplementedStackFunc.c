#define _CRT_SECURE_NO_WARNINGS 1

#include"QueueImplementedStackFunc.h"
#include"QueueFunc.h"

MyStack* myStackCreate() //初始化
{
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	if (!obj)
	{
		perror("malloc\n");
		return NULL;
	}
	Qinit(&obj->q1);
	Qinit(&obj->q2);
	return obj;
}

void myStackPush(MyStack* obj, int x) //入栈
{
	if (Qempty(&obj->q1))
		Qpush(&obj->q1, x);
	else
		Qpush(&obj->q2, x);
}

int myStackPop(MyStack* obj) //出栈
{
	Queue* pqempty = &obj->q1;
	Queue* pqnotempty = &obj->q2;
	if (Qempty(&obj->q2))
	{
		pqempty = &obj->q2;
		pqnotempty = &obj->q1;
	}
	while (pqnotempty->size > 1)
	{
		Qpush(pqempty, Qfront(pqnotempty));
		Qpop(pqnotempty);
	}
	int top = Qfront(pqnotempty);
	Qpop(pqnotempty);
	return top;
}

int myStackTop(MyStack* obj) //获取栈顶元素
{
	Queue* pqnotempty = &obj->q2;
	if (Qempty(&obj->q2))
		pqnotempty = &obj->q1;
	return Qback(pqnotempty);
}

bool myStackEmpty(MyStack* obj) //判断栈是否为空
{
	return Qempty(&obj->q1) && Qempty(&obj->q2);
}

void myStackFree(MyStack* obj) //销毁
{
	Qdestroy(&obj->q1);
	Qdestroy(&obj->q2);
	free(obj);
}