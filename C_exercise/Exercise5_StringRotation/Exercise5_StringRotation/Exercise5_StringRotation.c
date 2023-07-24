#define _CRT_SECURE_NO_WARNINGS 1
//【旋转字符串】
//实现一个函数，功能是将字符串中左侧的n个字符旋转到右侧
//如：ABCD旋转1个字符得到BCDA，ABCD旋转2个字符得到CDAB

#include<stdio.h>
#include<string.h>

char* rotate1(char* arr, int n, int len)
{
	char tmp = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = *arr;
		for (int j = 1; j < len; j++)
			arr[j - 1] = arr[j];
		arr[len - 1] = tmp;
	}
	return arr;
}

void reverse(char* l, char* r)
{
	char tmp = 0;
	while (r > l)
	{
		tmp = *r;
		*r = *l;
		*l = tmp;
		l++;
		r--;
	}
}

char* rotate2(char* arr, int n, int len)
{
	char* end = arr + len - 1;
	char* r = arr + n - 1;
	reverse(arr, r);
	reverse(r + 1, end);
	reverse(arr, end);
	return arr;
}

int main()
{
	char arr[100] = { 0 };
	int len = 0, n = 0;
	scanf("%s", arr);
	fflush(stdin);  //清理标准输入缓冲区
	len = strlen(arr);
	n = 0;
	scanf("%d", &n);
	fflush(stdin);  //清理标准输入缓冲区
	printf("%s\n\n", rotate1(arr, n, len));

	scanf("%s", arr);
	fflush(stdin);  //清理标准输入缓冲区
	len = strlen(arr);
	n = 0;
	scanf("%d", &n);
	fflush(stdin);  //清理标准输入缓冲区
	printf("%s\n", rotate2(arr, n, len));
	return 0;
}