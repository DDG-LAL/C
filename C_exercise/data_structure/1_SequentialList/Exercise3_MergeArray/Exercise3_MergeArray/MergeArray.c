#define _CRT_SECURE_NO_WARNINGS 1
//【合并有序数组】
//给出两个按非递减顺序排列的整型数组nums1和nums2，另有两个整数m和n，分别为nums1和nums2的元素数目
//要求合并nums2到nums1中，使合并后的数组同样按非递减顺序排列
//合并后数组不应由函数返回，而是存储在数组nums1中
//示例：
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]

#include<stdlib.h>
#include<stdio.h>

void merge(int* nums1, int m, int* nums2, int n) //两个数组同时从尾部向前遍历一次，较大值放在nums1尾部
{
	int end1 = m - 1, end2 = n - 1, end3 = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
			nums1[end3--] = nums1[end1--];
		else
			nums1[end3--] = nums2[end2--];
	}
	//若nums1未遍历完，则无需继续处理
	//若nums2未遍历完，需要把nums2中剩下元素传入nums1
	while (end2 >= 0)
		nums1[end3--] = nums2[end2--];
}

int main()
{
	int a[14] = { 0,1,1,3,3,4,5,34,51 };
	int b[] = { 1,2,3,3,14 };
	merge(a, 9, b, 5);
	for (int i = 0; i < 14; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}