#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LLdatatype;
typedef struct SingleLinkedListNode
{
	LLdatatype data;
	struct Node* next;
}Node;


void LLprint(Node* phead); //¥Ú”°

void LLpushfront(Node** phead, LLdatatype x); //Õ∑≤Â
void LLpushback(Node** phead, LLdatatype x); //Œ≤≤Â