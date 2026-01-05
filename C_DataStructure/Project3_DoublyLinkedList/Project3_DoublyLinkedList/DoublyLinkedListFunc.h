#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLLdatatype;
typedef struct DoublyLinkedListNode
{
	DLLdatatype data;
	struct DoublyLinkedListNode* prev;
	struct DoublyLinkedListNode* next;
}DLLnode;

DLLnode* BuyDLLNode(DLLdatatype data); //创建结点
DLLnode* DLLcreate(); //初始化

void DLLprint(DLLnode* phead); //打印

void DLLpushback(DLLnode* phead, DLLdatatype x); //尾插
void DLLpopback(DLLnode* phead); //尾删

void DLLpushfront(DLLnode* phead, DLLdatatype x); //头插
void DLLpopfront(DLLnode* phead); //头删