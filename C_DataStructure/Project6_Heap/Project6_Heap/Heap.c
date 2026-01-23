#define _CRT_SECURE_NO_WARNINGS 1

#include"HeapFunc.h"

void testpush()
{
	int a[] = { 0,1,6,7,3,2,9,2,1,8,5,6 };
	HP hp;
	HP* php = &hp;
	HPinit(php);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		HPpush(php, a[i]);
	while (!HPempty(php))
	{
		printf("%d ", HPtop(php));
		HPpop(php);
	}
	printf("\n\n");
	HPdestroy(php);
}

int main()
{
	testpush();
	int a[] = { 0,1,6,7,3,2,9,2,1,8,5,6 };
	HeapSort1(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		printf("%d ", a[i]);
	printf("\n\n");

	int b[] = { 11,3,6 };
	HeapSort2(b, sizeof(b) / sizeof(b[0]));
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i)
		printf("%d ", b[i]);
	printf("\n\n");

	//CreateTopkData(); //创建数据
	PrintTopK(10);

	return 0;
}