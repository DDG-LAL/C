#define _CRT_SECURE_NO_WARNINGS 1
//�����Ͼ���
//���Ͼ���ÿ�е�Ԫ�ش����ҵ�����ÿ�е�Ԫ�ش��ϵ��µ���
//��һ��3��3���������Ͼ����в���ĳ�������Ƿ����

#include<stdio.h>

void FindNum(int target, int arr[3][3], int* pr, int* pc)
{
	int x = *pr - 1;
	int y = 0;
	while (x >= 0 && y < *pc)  //����ڱ�����ά���飬���ַ���ʱ�临�Ӷȸ���
	{
		if (target > arr[x][y])  //��Ŀ����ڵ�ǰ���������ų�����
			++y;
		else if (target < arr[x][y])  //��Ŀ��С�ڵ�ǰ���������ų�����
			--x;
		else  //��Ŀ����ڵ�ǰ���������¼
		{
			*pr = x;
			*pc = y;
			return;
		}
	}
	*pr = -1;  //��δ�ҵ�Ŀ�꣬��ָ��ָ������͸�ֵΪ-1
	*pc = -1;
}
//��FindNum�����У�����pc��pr�Ⱦ߱����뺯���Ĳ��������ʣ��־߱��������ݵ�����
//���ֲ�����Ϊ�����Ͳ���

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
		printf("%d��%d��\n", r, c);
	return 0;
}