#define _CRT_SECURE_NO_WARNINGS 1
//【杨氏矩阵】
//杨氏矩阵每行的元素从左到右递增，每列的元素从上到下递增
//在一个3×3的整数杨氏矩阵中查找某个整数是否存在

#include<stdio.h>

void FindNum(int target, int arr[3][3], int* pr, int* pc)
{
	int x = *pr - 1;
	int y = 0;
	while (x >= 0 && y < *pc)  //相比于遍历二维数组，这种方法时间复杂度更低
	{
		if (target > arr[x][y])  //若目标大于当前的数，则排除该列
			++y;
		else if (target < arr[x][y])  //若目标小于当前的数，则排除该行
			--x;
		else  //若目标等于当前的数，则记录
		{
			*pr = x;
			*pc = y;
			return;
		}
	}
	*pr = -1;  //若未找到目标，则将指针指向的整型赋值为-1
	*pc = -1;
}
//在FindNum函数中，参数pc和pr既具备传入函数的参数的性质，又具备返回数据的作用
//这种参数即为返回型参数

int main()
{
	int arr[3][3] = { {1,4,7},
					  {2,5,8},
					  {3,6,9} };
	int t = 7, c = 3, r = 3;
	FindNum(t, arr, &r, &c);
	if (c < 0)
		printf("failed\n");
	else
		printf("%d行%d列\n", r, c);
	return 0;
}