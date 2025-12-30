#define _CRT_SECURE_NO_WARNINGS 1
//【模拟实现atoi】
//将一个字符串转化成一个整型的数
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
	assert(s);  //避免空指针
	status = NG;
	int flag = 1;
	if (*s == '\0')  //避免空字符串
		return 0;
	while (isspace(*s))  //跳过空字符
		++s;
	if (!isdigit(*s) && *s != '-' && *s != '+')  //避免非数字或正负号的字符
		return 0;
	if (*s == '-')  //处理负号
	{
		flag = -1;
		++s;
	}
	else if (*s == '+')  //处理正号
	{
		flag = 1;
		++s;
	}
	long long num = 0;
	while (isdigit(*s))
	{
		num *= 10;
		num += (*s - '0') * flag;
		if (num >= INT_MAX)  //处理越界情况
			return INT_MAX;  
		if (num <= INT_MIN)  //处理越界情况
			return INT_MIN;  
		++s;
	}
	if (*s == '\0')
		status = OK;
	return (int)num;
}


int main()
{
	char a[100] = "       -1278k93";
	int n = my_atoi(a);
	if (status == OK)
		printf("%d\n", n);
	else
		printf("%d\nerr\n", n);
	return 0;
}