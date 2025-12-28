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


void LLprint(Node* phead); //¥Ú”°

void LLpushfront(Node** pphead, LLdatatype x); //Õ∑≤Â
void LLpushback(Node** pphead, LLdatatype x); //Œ≤≤Â

void LLpopfront(Node** pphead); //Õ∑…æ
void LLpopback(Node** pphead); //Œ≤…æ
