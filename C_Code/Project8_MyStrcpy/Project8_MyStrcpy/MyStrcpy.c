//ʵ�ֿ⺯��strcpy�Ĺ��ܣ����Ż�����

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

//�ȼ�1��ʵ�ֹ���
void my_strcpy1(char* des, char* src)
{
	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}
	*des = *src;
}

//�ȼ�2�������
void my_strcpy2(char* des, char* src)
{
	while (*des++ = *src++)
	{
		;
	}
}

//�ȼ�3��ʹ�ö��ԣ�����Կ�ָ����н�����
void my_strcpy3(char* des, char* src)
{
	assert((des != NULL) && (src != NULL));  //���ԣ�ֻ����des��srcͬʱ��ΪNULLʱ�����������򱨴���Ҫassert.h��
	while (*des++ = *src++)
	{
		;
	}
}

//�ȼ�4��ʹ��const�������������н׶η����Ĵ�����¶�ڱ���׶�
void my_strcpy4(char* des, const char* src)
{
	assert(des && src);
	while (*des++ = *src++)  //����дΪ(*src++ = *des++)������*src��const���Σ������޸ģ���ֱ�ӱ���
	{                        //������const���������н׶β��ܷ��ִ�����Ϊ��䱾��û���﷨����
		;
	}
}

//�ȼ�5��ʹ�÷���ֵ��ʹ�ú����ܹ�ʵ����ʽ����
char* my_strcpy5(char* des, char* src)
{
	assert(des && src);
	char* ret = des;
	while (*des++ = *src++)
	{
		;
	}
	return ret;
}

//���Ƶأ�ʵ�ֿ⺯��strlen�Ĺ��ܲ��Ż�����
int my_strlen(const char* arr)
{
	assert(arr);
	int count = 0;
	while (*arr++ != '\0')
	{
		count++;
	}
	return count;
}

int main()
{
	char arr1[] = "abcdefg";
	char arr2[10] = "xxxxxxxxx";
	my_strcpy1(arr2, arr1);
	printf("%s\n", arr2);

	char arr3[] = "abcdefg";
	char arr4[10] = "xxxxxxxxx";
	my_strcpy2(arr4, arr3);
	printf("%s\n", arr4);

	char arr5[] = "abcdefg";
	char arr6[10] = "xxxxxxxxx";
	my_strcpy3(arr6, arr5);
	printf("%s\n", arr6);

	char arr7[] = "abcdefg";
	char arr8[10] = "xxxxxxxxx";
	my_strcpy4(arr8, arr7);
	printf("%s\n", arr8);

	char arr9[] = "abcdefg";
	char arr10[10] = "xxxxxxxxx";
	printf("%s\n", my_strcpy5(arr10, arr9));

	printf("%d\n", my_strlen("1234567"));
	return 0;
}