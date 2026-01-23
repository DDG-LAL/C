#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

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


void HeapSort1(HPdatatype* a, int size); //将数组数据逐个插入一个新的堆来完成建堆，然后通过pop排序
void HeapSort2(HPdatatype* a, int size); //堆排序

void CreateTopkData(); //创建数据，用于TopK问题

void PrintTopK(int k); //TopK问题，求最大的k个数，建小堆
