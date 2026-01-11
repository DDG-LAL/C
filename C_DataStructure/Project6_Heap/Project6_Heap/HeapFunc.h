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
void Swap(HPdatatype* x, HPdatatype* y); //交换数据

void Siftup(HPdatatype* data, int child); //向上调整算法
void HPpush(HP* php, HPdatatype x); //插入数据

bool HPempty(HP* php); //判断堆是否为空
int HPsize(HP* php); //获取堆内数据个数

void Siftdown(HPdatatype* data, int parent, int size); //向下调整算法
void HPpop(HP* php); //删除堆顶数据
HPdatatype HPtop(HP* php); //获取堆顶数据

void HPdestroy(HP* php); //销毁