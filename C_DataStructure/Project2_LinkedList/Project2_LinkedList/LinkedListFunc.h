#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LLdatatype;
typedef struct Node
{
	LLdatatype a;
	Node* next;
}Node;