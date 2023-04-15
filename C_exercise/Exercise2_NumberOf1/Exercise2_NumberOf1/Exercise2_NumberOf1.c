#define _CRT_SECURE_NO_WARNINGS 1

//求一个数在内存中的二进制序列中1的个数

#include<stdio.h>

int Number1(int a)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		sum += a & 1;
		a = a >> 1;
	}
	return sum;
}

int Number2(int a)
{
	int sum = 0;
	return sum;
}

int Number3(int a)
{
	int sum = 0;
	return sum;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d %d %d", Number1(a), Number2(a), Number3(a));
	return 0;
}