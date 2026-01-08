#define _CRT_SECURE_NO_WARNINGS 1

#include"CircularQueueFunc.h"

MyCircularQueue* myCircularQueueCreate(int k) //构造器，设置队列长度为k
{
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (!obj)
	{
		perror("malloc\n");
		return NULL;
	}
	obj->len = k;
	obj->data = (int*)malloc(sizeof(int) * (obj->len + 1));
	obj->front = obj->rear = 0;
	return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) //检查循环队列是否为空
{
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) //检查循环队列是否已满
{
	return (obj->rear + 1) % (obj->len + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) //插入一个元素，成功插入则返回true
{
	assert(obj);
	if (!myCircularQueueIsFull(obj))
	{
		obj->data[obj->rear] = value;
		obj->rear = (obj->rear + 1) % (obj->len + 1);
		return true;
	}
	else
		return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) //删除一个元素，成功删除则返回true
{
	if (!myCircularQueueIsEmpty(obj))
	{
		obj->front = (obj->front + 1) % (obj->len + 1);
		return true;
	}
	else
		return false;
}

int myCircularQueueFront(MyCircularQueue* obj) //获取队头元素，若队列为空则返回-1
{
	if (!myCircularQueueIsEmpty(obj))
		return obj->data[obj->front];
	else
		return -1;
}

int myCircularQueueRear(MyCircularQueue* obj) //获取队尾元素，若队列为空则返回-1
{
	if (!myCircularQueueIsEmpty(obj))
		return obj->data[((obj->rear - 1) + (obj->len + 1)) % (obj->len + 1)];
	else
		return -1;
}

void myCircularQueueFree(MyCircularQueue* obj) //销毁
{
	free(obj->data);
	free(obj);
}
