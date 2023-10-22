#define _CRT_SECURE_NO_WARNINGS 1
//��ģ��ʵ��atoi��
//��һ���ַ���ת����һ�����͵���
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>

enum S
{
	OK,
	NG
} status;

int my_atoi(const char* s)
{
	assert(s);  //�����ָ��
	status = NG;
	int flag = 1;
	if (*s == '\0')  //������ַ���
		return 0;
	while (isspace(*s))  //�������ַ�
		++s;
	if (!isdigit(*s) && *s != '-' && *s != '+')  //��������ֻ������ŵ��ַ�
		return 0;
	if (*s == '-')  //������
	{
		flag = -1;
		++s;
	}
	else if (*s == '+')  //��������
	{
		flag = 1;
		++s;
	}
	long long num = 0;
	while (isdigit(*s))
	{
		num *= 10;
		num += (*s - '0') * flag;
		if (num >= INT_MAX)  //����Խ�����
			return INT_MAX;  
		if (num <= INT_MIN)  //����Խ�����
			return INT_MIN;  
		++s;
	}
	if (*s == '\0')
		status = OK;
	return (int)num;
}


int main()
{
	char a[100] = "       -1278l93";
	int n = my_atoi(a);
	if (status == OK)
		printf("%d\n", n);
	else
		printf("%d\nerr\n", n);
	return 0;
}