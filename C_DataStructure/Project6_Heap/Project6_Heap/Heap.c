#define _CRT_SECURE_NO_WARNINGS 1

#include"HeapFunc.h"

void testpush(HP* php)
{
	HPpush(php, 0);
	HPpush(php, 1);
	HPpush(php, 6);
	HPpush(php, 7);
	HPpush(php, 3);
	HPpush(php, 2);
	HPpush(php, 9);
	HPpush(php, 2);
	HPpush(php, 1);
}

int main()
{
	HP hp;
	HP* php = &hp;
	HPinit(php);
	testpush(php);
	return 0;
}