#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LLdatatype;
typedef struct SingleLinkedListNode
{
	LLdatatype data;
	struct SingleLinkedListNode* next;
}Node;


void LLprint(const Node* phead); //打印

void LLpushfront(Node** pphead, LLdatatype x); //头插
void LLpushback(Node** pphead, LLdatatype x); //尾插

void LLpopfront(Node** pphead); //头删
void LLpopback(Node** pphead); //尾删

Node* LLsearch(const Node* phead, LLdatatype x); //查找

void LLinsertBefore(Node** pphead, Node* pos, LLdatatype x); //指定位置pos前插入
void LLinsertAfter(Node* pos, LLdatatype x); //指定位置pos后插入

void LLerase(Node** pphead, Node* pos); //指定位置删除
void LLeraseAfter(Node* pos); //指定位置的后一个位置删除

void LLdestroy(Node* phead); //销毁
void LLdestroy2(Node** pphead); //销毁，二级指针版本
