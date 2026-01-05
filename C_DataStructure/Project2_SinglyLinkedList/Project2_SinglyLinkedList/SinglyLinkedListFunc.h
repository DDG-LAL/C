#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLLdatatype;
typedef struct SinglyLinkedListNode
{
	SLLdatatype data;
	struct SinglyLinkedListNode* next;
}SLLnode;


void SLLprint(const SLLnode* phead); //打印
SLLnode* BuySLLNode(SLLdatatype x); //创建结点


void SLLpushfront(SLLnode** pphead, SLLdatatype x); //头插
void SLLpushback(SLLnode** pphead, SLLdatatype x); //尾插

void SLLpopfront(SLLnode** pphead); //头删
void SLLpopback(SLLnode** pphead); //尾删

SLLnode* SLLsearch(const SLLnode* phead, SLLdatatype x); //查找

void SLLinsertBefore(SLLnode** pphead, SLLnode* pos, SLLdatatype x); //指定位置pos前插入
void SLLinsertAfter(SLLnode* pos, SLLdatatype x); //指定位置pos后插入

void SLLerase(SLLnode** pphead, SLLnode* pos); //指定位置删除
void SLLeraseAfter(SLLnode* pos); //指定位置的后一个位置删除

void SLLdestroy(SLLnode* phead); //销毁
void SLLdestroy2(SLLnode** pphead); //销毁，二级指针版本
