#define _CRT_SECURE_NO_WARNINGS 1

#include"SortFunc.h"

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n) //直接插入排序
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int cur = a[i + 1];
		while (end >= 0)
		{
			if (a[end] < cur) //降序
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = cur;
	}
} //时间复杂度O(N^2)

void ShellSort(int* a, int n) //希尔排序
{
	int gap = n;
	while (gap > 1) //当gap>1时为预排序，当gap=1时为直接插入排序
	{
		gap = gap / 3 + 1; //gap一直缩小，最终必须等于1
		for (int i = 0; i < n - gap; ++i) //分组进行步长为gap的直接插入排序
		{
			int end = i;
			int cur = a[i + gap];
			while (end >= 0)
			{
				if (a[end] < cur) //降序
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = cur;
		}
		//for (int j = 0; j < gap; ++j)
		//{
		//	for (int i = j; i < n - gap; i += gap)
		//	{
		//		int end = i;
		//		int cur = a[i + gap];
		//		while (end >= 0)
		//		{
		//			if (a[end] < cur)
		//			{
		//				a[end + gap] = a[end];
		//				end -= gap;
		//			}
		//			else
		//				break;
		//		}
		//		a[end + gap] = cur;
		//	}
		//}
	}
} //时间复杂度≈O(N^1.3)

void SelectSort(int* a, int n) //直接选择排序
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int max = left, min = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[max] < a[i])
				max = i;
			if (a[min] > a[i])
				min = i;
		}
		Swap(&a[max], &a[left]); //降序
		if (min == left)
			min = max;
		Swap(&a[min], &a[right]);
		left++;
		right--;
	}
}

void AdjustDown(int* a, int parent, int size) //向下调整算法
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child]) //小堆
			child++;
		if (a[child] < a[parent]) //小堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n) //堆排序
{
	for (int i = (n - 2) / 2; i >= 0; --i) //建堆，排降序建小堆
		AdjustDown(a, i, n);
	for (int j = n - 1; j > 0; --j)
	{
		Swap(&a[0], &a[j]);
		AdjustDown(a, 0, j);
	}
}

void BubbleSort(int* a, int n) //冒泡排序
{
	for (int j = n - 1; j > 0; --j)
	{
		bool exchange = true;
		for (int i = 0; i < j; ++i)
		{
			if (a[i] < a[i + 1]) //降序
			{
				Swap(&a[i], &a[i + 1]);
				exchange = false;
			}
		}
		if (exchange)
			break;
	}
}

int GetMidIndex(int* a, int left, int right) //三数取中，对key优化
{
	int mid = left + (right - left) / 2;
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])
			return left;
		else if (a[mid] < a[right])
			return right;
		else
			return mid;
	}
	else //a[left] < a[right]
	{
		if (a[mid] < a[left])
			return left;
		else if (a[mid] > a[right])
			return right;
		else
			return mid;
	}
}

int Partsort1(int* a, int left, int right) //单次排序(Hoare法)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);
	int key = left;
	while (left < right)
	{	//left找小，right找大，找到后交换
		while (left < right && a[right] <= a[key]) //先判断后访问
			right--;
		while (left < right && a[left] >= a[key]) //先判断后访问
			left++;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]); //由于right先动，必然会相遇在比a[key]大的位置
	return left;
}

int Partsort2(int* a, int left, int right) //单次排序(挖坑法)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyval = a[left], hole = left;
	while (left < right)
	{	//left找小，right找大，轮流找，每找到一次就填hole，并更新hole的位置
		while (left < right && a[right] <= keyval) //先判断后访问
			right--;
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] >= keyval) //先判断后访问
			left++;
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = keyval; //必然相遇在hole位置
	return left;
}

int Partsort3(int* a, int left, int right) //单次排序(前后指针法)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int cur = left, key = left;
	while (cur <= right)
	{	//cur找大，找到后++left，然后交换
		while (cur <= right && a[cur] <= a[key]) //先判断后访问
			cur++;
		if (cur <= right) //避免越界
			Swap(&a[++left], &a[cur++]); //交换之前left++，交换之后cur++
	}
	Swap(&a[key], &a[left]); //left停下的位置必然大于等于a[key]
	return left;
}

int Partsort4(int* a, int left, int right) //单次排序(前后指针法)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left, cur = left + 1;
	while (cur <= right)
	{	//cur找大，找到后++left，然后交换
		if (a[cur] > a[keyi] && ++left != cur) //没有找到时不会执行++left
			Swap(&a[cur], &a[left]);
		cur++;
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

void QuickSort(int* a, int begin, int end) //快速排序
{
	if (begin >= end) //返回条件: 1.区间只有一个值 2.区间不存在
		return;
	int key = Partsort1(a, begin, end); //前序
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
} //时间复杂度O(N*logN)

void QuickSort_NonRecursive(int* a, int begin, int end) //快速排序(非递归，利用栈)
{
	ST st;
	ST* pst = &st;
	STinit(pst);
	STpush(pst, begin); //左边界入栈
	STpush(pst, end);   //右边界入栈
	while (!STempty(pst))
	{
		int right = STtop(pst);
		STpop(pst);
		int left = STtop(pst);
		STpop(pst);
		int key = Partsort1(a, left, right); //确定一个key
		if (key + 1 < right)
		{
			STpush(pst, key + 1);
			STpush(pst, right);
		}
		if (left < key - 1)
		{
			STpush(pst, left);
			STpush(pst, key - 1);
		}
	}
	STdestroy(pst);
}

void _MergeSort(int* a, int left, int right, int* tmp) //归并排序子函数
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2; //遇到奇数时mid会向下取整
	_MergeSort(a, left, mid, tmp); 
	_MergeSort(a, mid + 1, right, tmp); //后序
	int left1 = left, right1 = mid;
	int left2 = mid + 1, right2 = right;
	int tmpi = left;
	while (left1 <= right1 && left2 <= right2)
	{
		if (a[left1] > a[left2])
			tmp[tmpi++] = a[left1++];
		else
			tmp[tmpi++] = a[left2++];
	}
	while (left1 <= right1)
		tmp[tmpi++] = a[left1++];
	while (left2 <= right2)
		tmp[tmpi++] = a[left2++];
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n) //归并排序
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
} //时间复杂度O(N*logN)

void MergeSort_NonRecursive(int* a, int n) //归并排序(非递归)
{

}
