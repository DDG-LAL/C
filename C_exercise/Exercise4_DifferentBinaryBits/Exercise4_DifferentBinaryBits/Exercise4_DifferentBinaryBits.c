#define _CRT_SECURE_NO_WARNINGS 1
//【求不同的二进制位】
//输入两个整数，输出这两个整数对应的二进制序列中不同位的个数

#include<stdio.h>

//一般的方法，逐位比较
int diff1(int a, int b)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
		if (((a >> i) & 1) != ((b >> i) & 1))
			++sum;
	return sum;
}

//较好的方法，利用异或操作符，以及x = x & (x - 1)表达式的特殊性质
int diff2(int a, int b)
{
	int sum = 0, tmp = a ^ b;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		++sum;
	}
	return sum;
}

int main()
{
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	printf("%d %d", diff1(x, y), diff2(x, y));
	return 0;
}