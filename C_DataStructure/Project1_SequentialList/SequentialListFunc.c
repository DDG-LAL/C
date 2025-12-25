#define _CRT_SECURE_NO_WARNINGS 1

#include"SequentialListFunc.h"


void SLinit(SL* psl) //初始化
{
	psl->a = (SLdatatype*)malloc(sizeof(SLdatatype) * 4);
	if (psl->a == NULL)
	{
		perror("malloc");
		return;
	}
	psl->size = 0;
	psl->cap = 4;
}

void SLdestroy(SL* psl) //删除
{
	free(psl->a);
	psl->a = NULL;
	psl->size = 0;
	psl->cap = 0;
}

void SLprint(SL* psl) //打印
{
	for (int i = 0; i < psl->size; ++i)
		printf("%d ", psl->a[i]);
	printf("\n");
}

void SLcheckcap(SL* psl) //扩容判断
{
	if (psl->size == psl->cap)
	{
		SLdatatype* tmp = (SLdatatype*)realloc(psl->a, sizeof(SLdatatype) * (psl->cap * 2));
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		psl->a = tmp;
		psl->cap *= 2;
	}
}

void SLpushback(SL* psl, SLdatatype x) //尾插
{
	SLcheckcap(psl);
	psl->a[psl->size] = x; //最后一个元素下标为size-1，再往后一个下标即size
	psl->size++;
}

void SLpopback(SL* psl) //尾删
{
	psl->size--;
}