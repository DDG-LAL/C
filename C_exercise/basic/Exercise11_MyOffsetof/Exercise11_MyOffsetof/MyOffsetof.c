#define _CRT_SECURE_NO_WARNINGS 1
//【模拟实现offsetof】
//用宏实现计算结构体中某成员变量地址相对于首地址的偏移量

#define MY_OFFSETOF(type,memname) (size_t)&(((type*)0)->memname)  //以0为首地址，则取到的成员变量地址的值即等于偏移量
// ((type*)0): 将0强转为type*类型
// &(((type*)0)->memname): 将0视为type类型的结构体，对该结构体的memname成员取地址
// (size_t)&(((type*)0)->memname): 强转为size_t类型，此时取到的成员变量地址即为偏移量
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