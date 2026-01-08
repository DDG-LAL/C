#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int DLLdatatype;

//带头双向循环链表节点
typedef struct DoublyLinkedListNode
{
	DLLdatatype data;
	struct DoublyLinkedListNode* prev;
	struct DoublyLinkedListNode* next;
}DLLnode;

DLLnode* BuyDLLNode(DLLdatatype data); //创建节点
DLLnode* DLLcreate(); //初始化

bool DLLempty(DLLnode* phead); //判断链表是否为空

void DLLprint(DLLnode* phead); //打印

void DLLpushback(DLLnode* phead, DLLdatatype x); //尾插
void DLLpopback(DLLnode* phead); //尾删

void DLLpushfront(DLLnode* phead, DLLdatatype x); //头插
void DLLpopfront(DLLnode* phead); //头删

DLLnode* DLLsearch(DLLnode* phead, DLLdatatype x); //查找

void DLLinsert(DLLnode* pos, DLLdatatype x); //指定位置pos前插入
void DLLerase(DLLnode* pos); //指定位置删除

void DLLdestroy1(DLLnode* phead); //销毁
void DLLdestroy2(DLLnode* phead); //销毁
