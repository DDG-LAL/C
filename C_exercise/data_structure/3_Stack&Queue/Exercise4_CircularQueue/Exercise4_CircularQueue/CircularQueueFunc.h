#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef struct CircularQueue
{
	int front;
	int rear;
	int len;
	int* data;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k); //构造器，设置队列长度为k

bool myCircularQueueIsEmpty(MyCircularQueue* obj); //检查循环队列是否为空

bool myCircularQueueIsFull(MyCircularQueue* obj); //检查循环队列是否已满

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value); //插入一个元素，成功插入则返回true

bool myCircularQueueDeQueue(MyCircularQueue* obj); //删除一个元素，成功删除则返回true

int myCircularQueueFront(MyCircularQueue* obj); //获取队头元素，若队列为空则返回-1

int myCircularQueueRear(MyCircularQueue* obj); //获取队尾元素，若队列为空则返回-1

void myCircularQueueFree(MyCircularQueue* obj); //销毁
