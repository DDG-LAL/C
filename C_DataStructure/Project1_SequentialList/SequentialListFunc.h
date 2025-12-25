#pragma once

#include<stdlib.h>
#include<stdio.h>


////静态顺序表
//#define N 100
//typedef int SLdatatype;
//typedef struct Static_SeqList 
//{
//	SLdatatype a[N];
//	int size;
//}SeqList1;


//动态顺序表
typedef int SLdatatype;
typedef struct SeqList
{
	SLdatatype* a;
	int size; //有效数据数量
	int cap; //可用空间容量
}SL;


void SLinit(SL* psl); //初始化
void SLdestroy(SL* psl); //删除
void SLprint(SL* psl); //打印


void SLpushback(SL* psl, SLdatatype x); //尾插
void SLpushfront(SL* psl, SLdatatype x); //头插

void SLpopback(SL* psl); //尾删
void SLpopfront(SL* psl); //头删
