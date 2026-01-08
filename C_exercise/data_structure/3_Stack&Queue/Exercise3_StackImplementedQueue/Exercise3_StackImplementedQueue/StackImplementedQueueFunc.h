#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"StackFunc.h"

typedef struct StackImplementedQueue
{
	ST pushst;
	ST popst;
} MyQueue;

MyQueue* myQueueCreate(); //初始化

void myQueuePush(MyQueue* obj, int x); //入队列

int myQueuePop(MyQueue* obj); //出队列

int myQueuePeek(MyQueue* obj); //获取队头元素

bool myQueueEmpty(MyQueue* obj); //判断队列是否为空

void myQueueFree(MyQueue* obj); //销毁