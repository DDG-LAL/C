#define _CRT_SECURE_NO_WARNINGS 1
//��ģ��ʵ��offsetof��
//�ú�ʵ�ּ���ṹ����ĳ��Ա������ַ������׵�ַ��ƫ����

#define MY_OFFSETOF(type,memname) (size_t)&(((type*)0)->memname)  //��0Ϊ�׵�ַ����ȡ���ĳ�Ա������ַ��ֵ������ƫ����
#include<stdio.h>
#include<stddef.h>

typedef struct S
{
	char c1;
	double d;
	char c2;
	int i;
}S;

int main()
{
	printf("%d ", offsetof(S, c1));
	printf("%d ", offsetof(S, d));
	printf("%d ", offsetof(S, c2));
	printf("%d\n\n", offsetof(S, i));

	printf("%d ", MY_OFFSETOF(S, c1));
	printf("%d ", MY_OFFSETOF(S, d));
	printf("%d ", MY_OFFSETOF(S, c2));
	printf("%d\n", MY_OFFSETOF(S, i));
	return 0;
}