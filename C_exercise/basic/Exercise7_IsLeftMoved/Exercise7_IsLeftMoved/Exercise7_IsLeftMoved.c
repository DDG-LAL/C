#define _CRT_SECURE_NO_WARNINGS 1
//【判断左旋字符串】
//判断一个字符串是否由另一个字符串经过若干次左旋所得（已知两个字符串长度相等）
//如：字符串"abcd"为字符串"dabc"左旋一个字符所得

#include<stdio.h>
#include<string.h>

int IsLeftMoved1(const char* a, const char* b)  //判断b是否由a左旋所得
{
	char ctmp[20] = { 0 };
	strcpy(ctmp, a);
	int len = strlen(a);
	char tmp = 0;
	for (int i = 0; i < len; i++)  //先判断一次是否相同，若不同则左旋一次再判断，直到穷尽左旋的所有可能
	{
		if (!strcmp(ctmp, b))
			return 1;
		else  //将ctmp左旋一次
		{
			tmp = *ctmp;
			for (int j = 0; j < len - 1; ++j)
				*(ctmp + j) = *(ctmp + j + 1);
			*(ctmp + len - 1) = tmp;
		}
	}
	return 0;
}

int IsLeftMoved2(const char* a, const char* b)  //判断b是否由a左旋所得
{
	char tmp[20] = { 0 };
	strcpy(tmp, a);
	strncat(tmp, tmp, strlen(a));  //将a追加到其本身，此时得到的新字符串的子串中，包含了原本字符串左旋的所有可能性
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