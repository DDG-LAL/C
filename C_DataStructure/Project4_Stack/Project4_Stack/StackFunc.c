#define _CRT_SECURE_NO_WARNINGS 1

#include"StackFunc.h"

void STinit(ST* pst) //初始化
{
	assert(pst);
	pst->data = NULL;
	pst->cap = pst->top = 0;
}

bool STempty(ST* pst) //判断栈是否为空
{
	assert(pst);
	return 0 == pst->top;
}

void STpush(ST* pst, STdatatype x) //入栈
{
	assert(pst);
	if (pst->top == pst->cap)
	{
		int newcap = pst->cap == 0 ? 4 : pst->cap * 2;
		STdatatype* tmp = (STdatatype*)realloc(pst->data, sizeof(STdatatype) * newcap);
		if (!tmp)
		{
			perror("realloc\n");
			return;
		}
		pst->data = tmp;
		pst->cap = newcap;
	}
	pst->data[pst->top] = x;
	pst->top++;
}

void STpop(ST* pst) //出栈
{
	assert(pst);
	assert(!STempty(pst));
	pst->top--;
}

STdatatype STtop(ST* pst) //获取栈顶元素
{
	assert(pst);
	assert(!STempty(pst));
	return pst->data[pst->top - 1];
}

int STsize(ST* pst) //获取栈内元素个数
{
	assert(pst);
	return pst->top;
}

void STdestroy(ST* pst) //销毁
{
	assert(pst);
	free(pst->data);
	pst->data = NULL;
	pst->cap = pst->top = 0;

	printf("\ndestroyed\n");
}