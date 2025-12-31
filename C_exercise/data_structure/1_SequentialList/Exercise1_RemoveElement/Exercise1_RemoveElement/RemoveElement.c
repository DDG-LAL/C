#define _CRT_SECURE_NO_WARNINGS 1
//【移除数组指定元素】
//给出一个数组nums和一个值val，要求原地移除所有数值等于val的元素
//元素的顺序可能发生改变，移除后返回nums中与val不同的元素的数量
//假设nums中不等于val的元素数量为k，则需要执行以下操作：
//更改nums数组，使nums的前k个元素包含不等于val的元素，并返回 k
//nums的其余元素和nums的大小并不重要，
//示例：
//输入：nums = [3, 2, 2, 3], val = 3
//输出：2, nums = [2, 2, _, _]

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int removeElement(int* nums, int numsSize, int val) //遍历一次，若等于val则跳过，否则在原数组头部尾插覆盖
{
	int cur = 0, count = 0;
	while (cur < numsSize)
	{
		if (nums[cur] != val)
			nums[count++] = nums[cur++];
		else
			cur++;
	}
	return count;
}

int main()
{
	int a[] = { 1,1,3,3,4,5,1,1,34,1 };
	int k = removeElement(a, sizeof(a) / sizeof(a[0]), 1);
	printf("%d\n", k);
	for (int i = 0; i < k; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
