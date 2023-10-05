#define _CRT_SECURE_NO_WARNINGS 1
//���ҳ�����������
//1.��һ�����У���һ�����ǵ����ģ���������Ϊ�ɶԵģ��ҳ������������磺{1,2,3,2,3}�е�1��
//2.��һ�����У����������ǵ����ģ���������Ϊ�ɶԵģ��ҳ������������磺{1,2,2,3,3,5}�е�1��5��

#include<stdio.h>

int FindSingleNum1(int* arr, int len)
{
	int tmp = 0;
	for (int i = 0; i < len; ++i)  //��ȫ���������һ����ͬ��������0������������0���õ��䱾��
		tmp = tmp ^ arr[i];
	return tmp;
}

void FindSingleNum2(int* arr, int len, int* n1, int* n2)
{
	int tmp = 0, count = 0;
	int single1 = 0, single2 = 0;
	for (int i = 0; i < len; ++i)  //��ȫ�������һ�𣬵õ��������������Ľ���������tmp��
		tmp = tmp ^ arr[i];
	while (!(1 & (tmp >> count)))  //��tmp���ҳ�������λΪ1��һλ����һλ�������������ض��ǲ�ͬ��
		++count;				   //��������λΪ1��һλ��¼��count�У����ڷ��鴦��
	for (int i = 0; i < len; ++i)  //������λ�ĵ�countλ��Ϊ1������Ϊһ�飬��������ֵ���һ��
		if (1 & (arr[i] >> count))  //��ʱÿһ�鶼ֻ��һ����������������������������ɶ�
			single1 = single1 ^ arr[i];  //����countλ��Ϊ1������ȫ�����������һ�𣬵õ�����һ��������
	single2 = single1 ^ tmp;  //��һ����������tmp���õ���һ��������
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
