#define _CRT_SECURE_NO_WARNINGS 1
//����ͬ�Ķ�����λ��
//�����������������������������Ӧ�Ķ����������в�ͬλ�ĸ���

#include<stdio.h>

//һ��ķ�������λ�Ƚ�
int diff1(int a, int b)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
		if (((a >> i) & 1) != ((b >> i) & 1))
			++sum;
	return sum;
}

//�Ϻõķ��������������������Լ�x = x & (x - 1)���ʽ����������
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