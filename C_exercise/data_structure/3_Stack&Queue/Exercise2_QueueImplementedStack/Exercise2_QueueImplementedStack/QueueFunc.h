#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Qdatatype;

typedef struct QueueNode //队列结点
{
	struct QueueNode* next;
	Qdatatype data;
}Qnode;

typedef struct Queue //队列
{
	Qnode* phead;
	Qnode* ptail;
	int size;
}Queue;

void Qinit(Queue* pq); //初始化

bool Qempty(Queue* pq); //判断队列是否为空

void Qpush(Queue* pq, Qdatatype x); //入队列
void Qpop(Queue* pq); //出队列

Qdatatype Qfront(Queue* pq); //获取队头元素
Qdatatype Qback(Queue* pq); //获取队尾元素

int Qsize(Queue* pq); //获取队列内元素个数

void Qdestroy(Queue* pq); //销毁

