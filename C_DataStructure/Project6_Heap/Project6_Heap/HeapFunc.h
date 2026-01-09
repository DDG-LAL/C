#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPdatatype;

typedef struct Heap
{
	int size;
	int cap;
	HPdatatype* data;
}HP;

void HPinit(HP* php); //初始化

void Siftup(HPdatatype* data, int child);//向上调整算法
void HPpush(HP* php, HPdatatype x); //插入数据



void HPdestroy(HP* php); //销毁