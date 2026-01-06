#define _CRT_SECURE_NO_WARNINGS 1

#include"SequentialListFunc.h"


void SLinit(SL* psl) //初始化
{
	assert(psl);

	psl->data = (SLdatatype*)malloc(sizeof(SLdatatype) * 4);
	if (psl->data == NULL)
	{
		perror("malloc");
		return;
	}
	psl->size = 0;
	psl->cap = 4;
}

void SLdestroy(SL* psl) //删除
{
	assert(psl);

	free(psl->data);
	psl->data = NULL;
	psl->size = 0;
	psl->cap = 0;
}

void SLprint(SL* psl) //打印
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
		printf("%d ", psl->data[i]); //无法适配SLdatatype的类型
	printf("\n");
}

void SLcheckcap(SL* psl) //扩容判断
{
	assert(psl);

	if (psl->size == psl->cap)
	{
		SLdatatype* tmp = (SLdatatype*)realloc(psl->data, sizeof(SLdatatype) * (psl->cap * 2));
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		psl->data = tmp;
		psl->cap *= 2;
	}
}

void SLpushback(SL* psl, SLdatatype x) //尾插
{
	assert(psl);

	//SLcheckcap(psl);
	//psl->data[psl->size] = x; //最后一个元素下标为size-1，再往后一个下标即size
	//psl->size++;

	SLinsert(psl, psl->size, x); //复用
}

void SLpushfront(SL* psl, SLdatatype x) //头插
{
	assert(psl);

	/*SLcheckcap(psl);
	memmove(psl->data + 1, psl->data, sizeof(SLdatatype) * psl->size);
	psl->data[0] = x;
	psl->size++;*/

	SLinsert(psl, 0, x); //复用
}

void SLpopback(SL* psl) //尾删
{
	assert(psl);

	//if (psl->size > 0)
		//psl->size--;

	//assert(psl->size > 0); //为假则报错
	//psl->size--;

	SLerase(psl, psl->size - 1); //复用
}
void SLpopfront(SL* psl) //头删
{
	assert(psl);

	//assert(psl->size > 0); //为假则报错
	//memmove(psl->data, psl->data + 1, sizeof(SLdatatype) * psl->size);
	//psl->size--;

	SLerase(psl, 0); //复用
}

void SLinsert(SL* psl, int pos, SLdatatype x) //指定位置插入，pos为指定下标
{
	assert(psl);

	SLcheckcap(psl);
	assert(pos >= 0 && pos <= psl->size);
#pragma warning(push)
#pragma warning(disable:4013)
	memmove(psl->data + pos + 1, psl->data + pos, sizeof(SLdatatype) * psl->size - pos);
#pragma warning(pop)
	psl->data[pos] = x;
	psl->size++;
}

void SLerase(SL* psl, int pos) //指定位置删除void SLerase() 
{
	assert(psl);

	assert(pos >= 0 && pos < psl->size);
	memmove(psl->data + pos, psl->data + pos + 1, sizeof(SLdatatype) * psl->size - pos);
	psl->size--;
}

int SLsearch(SL* psl, SLdatatype x) //查找
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		if (psl->data[i] == x)
			return i;
	}
	return -1;
}

void SLmodify(SL* psl, int pos, SLdatatype x) //修改
{
	assert(psl);

	assert(pos >= 0 && pos < psl->size);
	psl->data[pos] = x;
}