#define _CRT_SECURE_NO_WARNINGS 1

#include"HeapFunc.h"

void HPinit(HP* php) //初始化
{
	assert(php);
	php->data = NULL;
	php->cap = php->size = 0;
}

void Siftup(HPdatatype* data, int child)//向上调整算法
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (data[parent] < data[child]) //大堆，要求父节点大于子节点
		{
			int tmp = data[parent];
			data[parent] = data[child];
			data[child] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}


void HPpush(HP* php, HPdatatype x) //插入数据
{
	assert(php);
	if (php->size == php->cap)
	{
		int newcap = php->cap == 0 ? 4 : php->cap * 2;
		HPdatatype* tmp = (HPdatatype*)realloc(php->data, sizeof(HPdatatype) * newcap);
		if (!tmp)
		{
			perror("realloc\n");
			return;
		}
		php->data = tmp;
		php->cap = newcap;
	}
	php->data[php->size] = x;
	php->size++;

	Siftup(php->data, php->size-1);//向上调整算法，确保插入数据之后堆的结构保持
}



void HPdestroy(HP* php) //销毁
{
	assert(php);

}