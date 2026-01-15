#define _CRT_SECURE_NO_WARNINGS 1

#include"HeapFunc.h"

void HPinit(HP* php) //初始化
{
	assert(php);
	php->data = NULL;
	php->cap = php->size = 0;
}

void Swap(HPdatatype* x, HPdatatype* y) //交换数据
{
	HPdatatype tmp = *x;
	*x = *y;
	*y = tmp;
}

void Siftup(HPdatatype* data, int child) //向上调整算法
{										 //向上调整算法的前提是除了data[child]之外的部分已经为堆

	//从child开始，用child与它的父节点进行比较，取较大/小的作为父节点
	//调整后以child的父节点作为child，再向上调整
	//若调整中途出现已经符合条件的情况，则无需继续调整，直接break
	//一直调整到根节点，无法再调整，此时结束

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (data[parent] < data[child]) //大堆，若父节点小于子节点则交换
		{
			Swap(&data[parent], &data[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HPpush(HP* php, HPdatatype x) //插入数据，插入后需要调堆
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

	Siftup(php->data, php->size - 1); //向上调整算法，确保插入数据之后堆的结构保持
}

bool HPempty(HP* php) //判断堆是否为空
{
	assert(php);
	return 0 == php->size;
}

int HPsize(HP* php) //获取堆内数据个数
{
	assert(php);
	return php->size;
}

void Siftdown(HPdatatype* data, int parent, int size) //向下调整算法
{													  //向下调整算法的前提是parent的左右子树均为堆

	//从parent开始，从parent以及两个子节点中选出最大/最小的作为parent
	//把被调整的子节点作为parent，再向下调整
	//若调整中途出现已经符合条件的情况，则无需继续调整，直接break
	//一直调整到叶子节点，无法再调整，此时结束

	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && data[child] < data[child + 1]) //选出较大子节点
			child++;
		if (data[parent] < data[child]) //大堆，选出较大子节点后，若父节点小于子节点则交换
		{
			Swap(&data[parent], &data[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HPpop(HP* php) //删除堆顶数据，首位数据交换，再删除尾数据，再调堆
{
	assert(php);
	assert(!HPempty(php));
	Swap(&php->data[0], &php->data[php->size - 1]); //首尾数据交换
	php->size--;

	Siftdown(php->data, 0, php->size); //向下调整算法，确保删除数据之后堆的结构保持
}

HPdatatype HPtop(HP* php) //获取堆顶数据
{
	assert(php);
	assert(!HPempty(php));
	return php->data[0];
}

void HPdestroy(HP* php) //销毁
{
	assert(php);
	free(php->data);
	php->data = NULL;
	php->size = php->cap = 0;
}