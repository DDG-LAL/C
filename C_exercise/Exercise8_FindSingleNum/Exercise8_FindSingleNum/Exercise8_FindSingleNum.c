#define _CRT_SECURE_NO_WARNINGS 1
//【找出单独的数】
//1.在一组数中，有一个数是单独的，其他数均为成对的，找出单独的数（如：{1,2,3,2,3}中的1）
//2.在一组数中，有两个数是单独的，其他数均为成对的，找出单独的数（如：{1,2,2,3,3,5}中的1和5）

#include<stdio.h>

int FindSingleNum1(int* arr, int len)
{
	int tmp = 0;
	for (int i = 0; i < len; ++i)  //将全部数异或在一起，相同的数异或得0，单独的数与0异或得到其本身
		tmp = tmp ^ arr[i];
	return tmp;
}

void FindSingleNum2(int* arr, int len, int* n1, int* n2)
{
	int tmp = 0, count = 0;
	int single1 = 0, single2 = 0;
	for (int i = 0; i < len; ++i)  //将全部数异或到一起，得到两个单独数异或的结果，存放在tmp中
		tmp = tmp ^ arr[i];
	while (!(1 & (tmp >> count)))  //在tmp中找出二进制位为1的一位，这一位上两个单独数必定是不同的
		++count;				   //将二进制位为1的一位记录在count中，用于分组处理
	for (int i = 0; i < len; ++i)  //二进制位的第count位上为1的数分为一组，其余的数分到另一组
		if (1 & (arr[i] >> count))  //此时每一组都只有一个单独数，并且组内其余的数都成对
			single1 = single1 ^ arr[i];  //将第count位上为1的组中全部的数异或在一起，得到其中一个单独数
	single2 = single1 ^ tmp;  //将一个单独数与tmp异或得到另一个单独数
	*n1 = single1; 
	*n2 = single2;
}

int main()
{
	int a1[] = { 4,5,3,5,7,4,3 };
	int len1 = sizeof(a1) / sizeof(a1[0]);

	int a2[] = { 7,7,3,9,5,4,9,6,1,5,6,8,3,1 };
	int len2 = sizeof(a2) / sizeof(a2[0]);
	int a = 0, b = 0;

	printf("%d\n", FindSingleNum1(a1, len1));
	FindSingleNum2(a2, len2, &a, &b);
	printf("%d %d\n", a, b);
	return 0;
}
