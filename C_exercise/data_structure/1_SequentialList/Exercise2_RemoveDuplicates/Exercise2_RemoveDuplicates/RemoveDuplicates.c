#define _CRT_SECURE_NO_WARNINGS 1
//【删除有序数组中的重复项】
//给出一个非严格递增排列的数组nums，要求原地删除重复出现的元素，使每个元素只出现一次，并返回删除后数组的新长度
//元素的相对顺序应保持一致
//考虑nums的唯一元素数量为k，去重后返回唯一元素的数量k
//nums的前k个元素应包含排序后的唯一数字，下标k-1之后的元素可以忽略
//示例：
//输入：nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//输出：5, nums = [0, 1, 2, 3, 4, _, _, _, _, _]

#include<stdlib.h>
#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) //遍历一次，若相同则跳过，否则在原数组头部尾插覆盖
{
	int src = 1, des = 0;
	while (src < numsSize)
	{
		if (nums[src] == nums[des])
			src++;
		else
			nums[++des] = nums[src++]; //先移动des再赋值
	}
	return des + 1;
}

int main()
{
	int a[] = { 1,1,3,3,4,5,12,12,34,41 };
	int k = removeDuplicates(a, sizeof(a) / sizeof(a[0]));
	printf("%d\n", k);
	for (int i = 0; i < k; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}