#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLLdatatype;
typedef struct DoublyLinkedList
{
	DLLdatatype data;
	struct DoublyLinkedList* prev;
	struct DoublyLinkedList* next;
}DLLnode;

