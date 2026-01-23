#define _CRT_SECURE_NO_WARNINGS 1

#include"HeapFunc.h"

void HeapSort1(HPdatatype* a, int size) //将数组数据逐个插入一个新的堆来完成建堆
{										//再逐个从堆顶取出数据放回数组来完成排序
	HP hp;								//缺点：需要写一个堆、空间复杂度高、来回拷贝数据
	HP* php = &hp;						//时间复杂度O(N*logN)
	HPinit(php);
	int i = 0;
	for (i = 0; i < size; ++i) //排升序，插入小堆
		HPpush(php, a[i]);
	i = 0;
	while (!HPempty(php))
	{
		a[i++] = HPtop(php);
		HPpop(php);
	}
	HPdestroy(php);
}

										//堆排序，整体时间复杂度O(N*logN)
void HeapSort2(HPdatatype* a, int size) //直接把原数组调整成堆，排降序，调成小堆
{										//完成建堆后通过向下调整算法来排序

	//for (int i = 1; i < size; ++i) //向上调整建堆，效率低，时间复杂度O(N*logN)
	//	Siftup(a, i);

	for (int i = (size - 2) / 2; i >= 0; --i) //向下调整建堆，效率高，时间复杂度O(N-logN)≈O(N)
		Siftdown(a, i, size);

	int end = size - 1;
	while (end)
	{
		Swap(&a[0], &a[end]); //首位数据交换，则堆顶最大数据放置在了数组末尾
		Siftdown(a, 0, end);  //忽略末尾数据，则剩下的数据除了堆顶之外都符合堆
		end--;				  //对剩下的数据向下调整
	}						  //注意下标end的处理，最后再end--
}

void CreateTopkData() //创建数据，用于TopK问题
{
	srand((unsigned int)time(NULL)); //初始化随机数
	int n = 1000000; //数据个数
	const char* filename = "TopK_data.txt";
	FILE* fin = fopen(filename, "w"); //打开文件
	if (!fin)
	{
		perror("fopen\n");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int data = (rand() * RAND_MAX + rand()) % 1000000; //产生0至999999的随机整数并写入
		fprintf(fin, "%d\n", data);
	}
	fclose(fin);
}

void PrintTopK(int k) //TopK问题，求最大的k个数，建小堆
{
	const char* filename = "TopK_data.txt";
	FILE* fout = fopen(filename, "r"); //打开文件
	if (!fout)
	{
		perror("fopen\n");
		return;
	}
	int* minheap = (int*)malloc(sizeof(int) * k); //申请数组空间
	if (!minheap)
	{
		perror("malloc\n");
		return;
	}
#pragma warning(push)
#pragma warning(disable:6031) //强制忽略C6031警告
	for (int i = 0; i < k; ++i)
		fscanf(fout, "%d", &minheap[i]); //将前k个数据写入数组
	for (int i = (k - 2) / 2; i >= 0; --i)
		Siftdown(minheap, i, k); //向下调整建堆
	int tmp = 0;
	while (!feof(fout)) //若文件指针到达文件尾，feof()返回0，否则返回非0值
	{
		fscanf(fout, "%d", &tmp);
		if (tmp > minheap[0])
		{
			minheap[0] = tmp;
			Siftdown(minheap, 0, k);
		}
	}
#pragma warning(pop)
#pragma warning(push)
#pragma warning(disable:6385) //强制忽略C6385警告
	for (int i = 0; i < k; ++i)
		printf("%d ", minheap[i]);
#pragma warning(pop)
	printf("\n\n");
	fclose(fout); //关闭文件
	free(minheap); //释放空间
}
