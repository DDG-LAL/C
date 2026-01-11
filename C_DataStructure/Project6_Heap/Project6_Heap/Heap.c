#define _CRT_SECURE_NO_WARNINGS 1

#include"HeapFunc.h"

void testpush(HP* php)
{
	int a[] = { 0,1,6,7,3,2,9,2,1,8,5,6 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		HPpush(php, a[i]);
}

int main()
{
	HP hp;
	HP* php = &hp;
	HPinit(php);
	testpush(php);
	HPpop(php);
	HPpop(php);
	HPpop(php);
	return 0;
}