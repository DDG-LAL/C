#define _CRT_SECURE_NO_WARNINGS 1
//【空格替换为%20】
//实现一个函数，将一个字符串中的每个空格替换成"%20"
//如：当字符串为"I am"，则操作后变为"I%20am"

#include<stdio.h>
#include<string.h>

void func20_1(char* str)  //效率较低的方法
{
	int len = strlen(str);
	char* r = str + len - 1;
	char* p = NULL;
	while ((p = strstr(str, " ")) != NULL)  //将空格的位置存放在指针p中
	{
		*(r + 3) = '\0';  //将字符串末尾向后移动两个字节
		while (r > p)  //将空格之后的整个字符串向后移动两个字节
		{
			*(r + 2) = *r;
			--r;
		}
		*p = '%';  //在空格的位置写入"%20"
		*(p + 1) = '2';
		*(p + 2) = '0';
		len += 2;  //长度增加2
		r = str + len - 1;  //更新字符串末尾指针
	}
}

void func20_2(char* str)  //效率较高的方法
{
	int spacenum = 0;
	char* p = str;
	while (*p != '\0')  //记录空格的数量
	{
		if (*p == ' ')
			++spacenum;
		++p;
	}
	--p;  //此时指针p指向操作前的字符串末尾位置
	char* end = p + 2 * spacenum;  //确定操作后的字符串末尾指针的位置
	while (end != p)
	{
		if (*p == ' ')  //遇到空格时在end处写入"%20"，p直接指向下一个位置
		{
			*end-- = '0';
			*end-- = '2';
			*end-- = '%';
			--p;
		}
		else  //未遇到空格时将字符从p处复制到end处
			*end-- = *p--;
	}
}

int main()
{
	char a[30] = "asd qwee rer";
	char b[30] = "asd qwee rer";
	func20_1(a);
	func20_2(b);
	printf(a);
	printf("\n\n");
	printf(b);
	printf("\n\n");
	printf("asd%20qwee%20rer\n\n");
	printf("asd%%20qwee%%20rer\n");  //正常打印'%'，避免被识别为格式说明符
	return 0;
}

