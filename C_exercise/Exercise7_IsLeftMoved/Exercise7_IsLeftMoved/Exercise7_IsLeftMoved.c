#define _CRT_SECURE_NO_WARNINGS 1
//���ж������ַ�����
//�ж�һ���ַ����Ƿ�����һ���ַ����������ɴ��������ã���֪�����ַ���������ȣ�
//�磺�ַ���"abcd"Ϊ�ַ���"dabc"����һ���ַ�����

#include<stdio.h>
#include<string.h>

int IsLeftMoved1(const char* a, const char* b)  //�ж�b�Ƿ���a��������
{
	char ctmp[20] = { 0 };
	strcpy(ctmp, a);
	int len = strlen(a);
	char tmp = 0;
	for (int i = 0; i < len; i++)  //���ж�һ���Ƿ���ͬ������ͬ������һ�����жϣ�ֱ������������п���
	{
		if (!strcmp(ctmp, b))
			return 1;
		else  //��ctmp����һ��
		{
			tmp = *ctmp;
			for (int j = 0; j < len - 1; ++j)
				*(ctmp + j) = *(ctmp + j + 1);
			*(ctmp + len - 1) = tmp;
		}
	}
	return 0;
}

int IsLeftMoved2(const char* a, const char* b)  //�ж�b�Ƿ���a��������
{
	char tmp[20] = { 0 };
	strcpy(tmp, a);
	strncat(tmp, tmp, strlen(a));  //��a׷�ӵ��䱾����ʱ�õ������ַ������Ӵ��У�������ԭ���ַ������������п�����
	if (strstr(tmp, b) != NULL)
		return 1;
	else
		return 0;
}

int main()
{
	char arr1[20] = "qwert";
	char arr2[20] = "ertqw";
	printf("%d %d\n", IsLeftMoved1(arr1, arr2), IsLeftMoved2(arr1, arr2));
	return 0;
}