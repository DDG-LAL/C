//实现库函数strcpy的功能，并优化代码

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

//等级1：实现功能
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

//等级2：代码简化
void my_strcpy2(char* des, char* src)
{
	while (*des++ = *src++)
	{
		;
	}
}

//等级3：使用断言，避免对空指针进行解引用
void my_strcpy3(char* des, char* src)
{
	assert((des != NULL) && (src != NULL));  //断言，只有在des和src同时不为NULL时才正常，否则报错（需要assert.h）
	while (*des++ = *src++)
	{
		;
	}
}

//等级4：使用const，将可能在运行阶段发生的错误显露在编译阶段
void my_strcpy4(char* des, const char* src)
{
	assert(des && src);
	while (*des++ = *src++)  //若错写为(*src++ = *des++)，由于*src被const修饰，不可修改，会直接报错
	{                        //若不加const，则在运行阶段才能发现错误，因为语句本身没有语法错误
		;
	}
}

//等级5：使用返回值，使得函数能够实现链式访问
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

//类似地，实现库函数strlen的功能并优化代码
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